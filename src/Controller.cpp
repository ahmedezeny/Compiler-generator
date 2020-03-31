//
// Created by zeny on 3/24/20.
//

#include "../include/Controller.h"
#include <fstream>
#include <sstream>
#include <string>


shared_ptr<Token> Controller::readToken(string path) {

    std::ifstream infile(path);

    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int a, b;
        if (!(iss >> a >> b)) { break; } // error

    // process pair (a,b)
    }

    return shared_ptr<Token>();
}

shared_ptr<Token> Controller::preProcess(vector<shared_ptr<Token>> tokens, int tokenNum) {
    return shared_ptr<Token>();
}

void Controller::minDfa() {
    vector<vector<shared_ptr<State>>> partitions;
    vector<shared_ptr<State>>s(this->getD().getStates().begin(),this->getD().getStates().end());

    for(int i=0;i<2;i++)
        partitions.push_back(split(s)[i]);

    vector<vector<shared_ptr<State>>> dummyPartitions=partitions;
    do{
        partitions=dummyPartitions;
        dummyPartitions=smash(partitions);
    }while(!containSamePartitions(partitions,dummyPartitions));
    setNewStates(partitions);
    reflectMinimizedDfa(partitions);
}

bool Controller::equalStates(vector<vector<shared_ptr<State>>> p, shared_ptr<State> s1, shared_ptr<State> s2){
    for(auto in:this->inputs) {
        if(areEqual(p,s1,s2,in)){
            continue;
        }else{
            return false;

        }
    }
    return true;
}

vector<vector<shared_ptr<State>>> Controller::smash(vector<vector<shared_ptr<State>>> p) {
    int newPartitionPointer=-1;
    vector<vector<shared_ptr<State>>> result;
    for (int i = 0; i < p.size(); i++) {
        vector<shared_ptr<State>>v1;
        v1.push_back(p[i][0]);
        result.push_back(v1);
        newPartitionPointer++;
        for (int j = 1; j < p[i].size(); j++) {
            bool luck=false;
            for(int r=newPartitionPointer;r<result.size();r++){
                if(equalStates( p,result[r][0], p[i][j])){
                    result[r].push_back(p[i][j]);
                    luck=true;
                    break;
                }
            }
            if(!luck){
                vector<shared_ptr<State>>v1;
                v1.push_back(p[i][j]);
                result.push_back(v1);
            }
        }
    }
    return result;
}


vector<vector<shared_ptr<State>>> Controller::split(vector<shared_ptr<State>> s){
    vector<vector<shared_ptr<State>>> p;
    vector<shared_ptr<State>>endStates;
    vector<shared_ptr<State>>nonEndStates;
    for(auto & i : s){
        if(i->isEndState()){
            endStates.push_back(i);
        } else
            nonEndStates.push_back(i);
    }
    p.push_back(nonEndStates);
    p.push_back(endStates);
    return p;
}

void Controller::getAllInputs(DFA A) {
    list<shared_ptr<State>>s=A.getStates();
    vector<char> result;
    for(auto i:s){
        for(auto j:i->getTrans()){
            result.push_back(j.first);
        }
    }
    vector<char> ::iterator ip;

    // Using std::unique
    ip = unique(result.begin(), result.end());

    // Resizing the vector so as to remove the und
    result.resize(std::distance(result.begin(), ip));
    this->inputs=result;

}

NFA Controller::oringAll(vector<NFA> A) {
    NFA *nfa;
    shared_ptr<State> newStartState;
    vector<NFA>::iterator it;
    for(it=A.begin();it!=A.end();it++){
        newStartState->setTransion('\0', it->getStartState());
        it->setStartState(newStartState);
    }
    return *nfa;
}

bool Controller::areEqual(vector<vector<shared_ptr<State>>>p,shared_ptr<State> s1, shared_ptr<State> s2, char in) {
    shared_ptr<State> t1;
    shared_ptr<State> t2;

    for(auto ss:s1->getTransion(in))
        t1=ss;  //that should be once

    for(auto ss:s2->getTransion(in))
        t2=ss;  //that should be once

    if(t1==NULL&&t2==NULL)
        return true;
    if(t1==NULL||t2==NULL)
        return false;

    return !(!t1->same(t2) || !inSameVector(p, t1, t2));

}

bool Controller::inSameVector(vector<vector<shared_ptr<State>>>p,shared_ptr< State>t1,shared_ptr< State>t2){
    for(const auto & i : p){
        if(statesExistInVector(i,t1,t2))
            return true;
    }
    return false;
}

bool Controller::statesExistInVector(vector<shared_ptr<State>>p,shared_ptr<State>t1,shared_ptr<State>t2){
    bool bingo1=false;
    bool bingo2=false;
    for(auto i:p){
        if(i->same(t1))
            bingo1=true;
        if(i->same(t2))
            bingo2=true;
    }
    return bingo1 && bingo2;
}

bool Controller::containSamePartitions(vector<vector<shared_ptr<State>>> v1, vector<vector<shared_ptr<State>>> v2) {
    if(v1.size()!=v2.size())
        return false;
    for(int i=0;i<v1.size();i++){
        if(v1[i].size()!=v2[i].size())
            return false;
        for(int j=0;j<v1[i].size();j++){
            if(!v1[i][j]->same(v2[i][j]))
                return false;
        }
    }

    return true;
}

void Controller::reflectMinimizedDfa(vector<vector<shared_ptr<State>>> partitions) {
    vector<shared_ptr<State>>sl(this->D.getStates().begin(),this->D.getStates().end());

    list<shared_ptr<State>> result;
    for(auto & partition : partitions){
        for(int j=1;j<partition.size()&&partition.size()>1;j++){
            mushTwoStates(partition[0], partition[j]);
        }
        result.push_back(partition[0]);
    }
    this->D.setStates(result);
}

void Controller::mushTwoStates( shared_ptr<State> state, shared_ptr<State>state1) {
    //iterate the vector of states
    for(auto i:this->D.getStates()){
        //for each state each state transfares to
        for(auto t:i->getTrans()){
            shared_ptr<State> t1;
            //get the only state it transfares to
            for(auto ss:t.second)
                t1=ss;  //that should be once

            if(state1==t1){                       //if this state is state1
                i->setTransion(t.first,state);    //let it point to state
            }
        }
    }
    if(state->isEndState()
        &&state1->isEndState()
        &&state1->getToken()->getPriority()<
        state->getToken()->getPriority())
        state->setToken(state1->getToken());

}

const vector<shared_ptr<Token>> &Controller::getTokens() const {
    return tokens;
}

void Controller::setTokens(const vector<shared_ptr<Token>> &tokens) {
    Controller::tokens = tokens;
}

const vector<NFA> &Controller::getA() const {
    return A;
}

void Controller::setA(const vector<NFA> &a) {
    A = a;
}

const NFA &Controller::getN() const {
    return N;
}

void Controller::setN(const NFA &n) {
    N = n;
}

const DFA &Controller::getD() const {
    return D;
}

void Controller::setD(const DFA &d) {
    D = d;
}

void Controller::setNewStates(const vector<vector<shared_ptr<State>>>& partitions) {
    list<shared_ptr<State>>r;
    for(auto & partition : partitions){
        for(const auto & j : partition){
            r.push_back(j);
        }
    }
    DFA d;
    d.setEndState(this->getD().getEndState());
    d.setStartState(this->getD().getStartState());
    d.setStates(r);
    this->setD(d);
}
/*
DFA Controller::nfaToDfa(NFA A) {
    list<shared_ptr<State>> states = A.getStates();
    unordered_map<set<shared_ptr<State>>, bool> DStates;
    unordered_map<set<shared_ptr<State>>, bool> DTran;
    set<shared_ptr<State>> s0 = epsClosure(A.getStartState(), '0');
    DStates.insert({s0, false});
    shared_ptr<State> t = getUnMarked(DStates);
    while (t->getToken()->getName() != "") {
        for (auto i = t->getTrans().begin(); i != t->getTrans().end(); ++i) {
            char input = i->first;
            set<shared_ptr<State>> u = epsClosure(epsClosure(t, input), '0');
            if (!checkD(u)) {
                DStates.insert({u, false});
            }
        }
        State t = getUnMarked(DStates);
    }
    return DFA();
}

NFA Controller::oringAll(vector<NFA> A) {
    NFA *nfa;
    shared_ptr<State> newStartState;
    vector<NFA>::iterator it;
    for (it = A.begin(); it != A.end(); it++) {
        newStartState->setTransion('\0', it->getStartState());
        it->setStartState(newStartState);
    }
    return *nfa;
}

set<shared_ptr<State>> Controller::epsClosure(shared_ptr<State> s, char input) {
    return s->getTransion(input);
}

set<shared_ptr<State>> Controller::epsClosure(set<shared_ptr<State>> s, char input) {
    set<shared_ptr<State>> res;
    for (auto it = s.begin(); it != s.end(); ++it) {
        set<shared_ptr<State>> temp = epsClosure(*it, input);
        res.insert(temp.begin(), temp.end());
    }
    return s;
}

shared_ptr<State> Controller::getUnMarked(unordered_map<set<shared_ptr<State>>, bool> &DStates) {
//    auto iterator = DStates.begin();
//    while (iterator != DStates.end()) {
//        if(!iterator->second)
//            return iterator->first;
//    }
//    return static_cast<shared_ptr<State>>(static_cast<shared_ptr<Token>>(nullptr));
}

bool Controller::checkD(set<shared_ptr<State>> set) {
    return false;
}

*/
