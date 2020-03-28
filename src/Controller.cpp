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

DFA Controller::minDfa(DFA A) {
    vector<vector<State>> partitions;
    vector<State>s(A.getStates().begin(),A.getStates().end());
    for(int i=0;i<2;i++)
        partitions.push_back(split(s)[i]);

    vector<vector<State>> dummyPartitions=partitions;
    do{
        partitions=dummyPartitions;
        dummyPartitions=smash(partitions);
    }while(!containSamePartitions(partitions,dummyPartitions));
    //todo wrappUP
    DFA D();
    return DFA();
}

bool Controller::equalStates(vector<vector<State>> p, State s1, State s2){
    for(auto in:this->inputs) {
        if(areEqual(p,s1,s2,in)){
            continue;
        }else{
            return false;

        }
    }
    return true;
}

vector<vector<State>> Controller::smash(vector<vector<State>> p) {
    int newPartitionPointer=-1;
    vector<vector<State>> result;
    for (int i = 0; i < p.size(); i++) {
        vector<State>v1;
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
                vector<State>v1;
                v1.push_back(p[i][j]);
                result.push_back(v1);
            }
        }
    }
    return result;
}


vector<vector<State>> Controller::split(vector<State> s){
    vector<vector<State>> p;
    vector<State>endStates;
    vector<State>nonEndStates;
    for(int i=0;i<s.size();i++){
        if(s[i].isEndState()){
            endStates.push_back(s[i]);
        } else
            nonEndStates.push_back(s[i]);
    }
    p.push_back(endStates);
    p.push_back(nonEndStates);
    return p;
}

void Controller::getAllInputs(DFA A) {
    list<State>s=A.getStates();
    vector<char> result;
    for(auto i:s){
        for(auto j:i.getTrans()){
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

bool Controller::areEqual(vector<vector<State>>p,State s1, State s2, char in) {
    shared_ptr<State> t1;
    shared_ptr<State> t2;

    for(auto ss:s1.getTransion(in))
        t1=ss;  //that should be once

    for(auto ss:s2.getTransion(in))
        t2=ss;  //that should be once

    if(t1==NULL&&t2==NULL)
        return true;
    if(t1==NULL||t2==NULL)
        return false;

    if(!t1->same(*t2)||!inSameVector(p,t1,t2))
        return false;

    return true;
}

bool Controller::inSameVector(vector<vector<State>>p,shared_ptr< State>t1,shared_ptr< State>t2){
    for(int i=0;i<p.size();i++){
        if(statesExistInVector(p[i],t1,t2))
            return true;
    }
    return false;
}

bool Controller::statesExistInVector(vector<State>p,shared_ptr<State>t1,shared_ptr<State>t2){
    bool bingo1=false;
    bool bingo2=false;
    for(auto i:p){
        if(i.same(*t1))
            bingo1=true;
        if(i.same(*t2))
            bingo2=true;
    }
    return bingo1 && bingo2;
}

bool Controller::containSamePartitions(vector<vector<State>> v1, vector<vector<State>> v2) {
    if(v1.size()!=v2.size())
        return false;
    for(int i=0;i<v1.size();i++){
        if(v1[i].size()!=v2[i].size())
            return false;
        for(int j=0;j<v1[i].size();j++){
            if(!v1[i][j].same(v2[i][j]))
                return false;
        }
    }

    return true;
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
