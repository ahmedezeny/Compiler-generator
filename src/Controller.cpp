//
// Created by zeny on 3/24/20.
//

#include "Controller.h"
#include <bits/stdc++.h>
#include <DFAState.h>


Controller::Controller() {}

Controller::~Controller() {

}

shared_ptr<Token>
Controller::preProcess(vector<shared_ptr<Token>> tokens, int tokenNum) {
    return shared_ptr<Token>();
}


set<shared_ptr<Token>> Controller::readToken(string path)
{

    std::ifstream infile(path);

    std::string line;
    int counter = 0 ;
    set <string> allname ;
    set < shared_ptr<Token> > allToken ;
    while (std::getline(infile, line)) {
        //   cout << counter << endl ;
        counter ++ ;
        /**     std::istringstream iss(line);
                string s ;
        */
        if (line[0] == '[' && line[line.size() -1 ] == ']') {

            string newline = line.substr(1, line.size() - 2  ) ;
            std::istringstream iss(newline);
            string s ;
            while (iss >> s) {
                shared_ptr<Token> t (new Token()) ;
                string name = "panc_[" + s + "]" ;
                t->setName(name) ;
                t->setPriority(counter);
                t->setPattern(s);
                if (allname.find(name) == allname.end()) {
                    allname.insert(name);
                    allToken.insert(t);
                }
            }


        } else if (line[0] == '{' && line[line.size() -1 ] == '}') {

            string newline = line.substr(1, line.size() - 2  ) ;
            std::istringstream iss(newline);
            string s ;
            while (iss >> s) {
                shared_ptr<Token> t (new Token()) ;
                t->setName(s) ;
                t->setPriority(counter);
                t->setPattern(s);
                if (allname.find(s) == allname.end()) {
                    allname.insert(s);
                    allToken.insert(t);
                }
            }


        } else if (line[0] != '{' && line[0] != ']') {
            // cout << line << endl ;
            int index = 0 ;
            string sname = "" ;
            for (int i = 0 ; i <  line.size() ; i++) {
                if (line[i] == ' ') {
                    continue ;
                }

                if (line[i] == '=' || line[i] == ':') {
                    index = i ;
                    break;
                }

                sname = sname + line[i] ;
            }

            if (index == 0 || sname == "") {
                cout << "eeeeeNow" << endl ;
            }

            shared_ptr<Token> t (new Token()) ;
            t->setName(sname) ;
            cout << line << endl ;
            string s = line.substr(index+1, line.size() - index+1) ;
            t->setPriority(counter);
            t->setPattern(s);
            if (allname.find(sname) == allname.end()) {
                allname.insert(sname);
                allToken.insert(t);
            }



        } else {
            cout << "error" << endl  ;
            break ;
        }


        // process pair (a,b)
    }

    return allToken;
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
DFA Controller::nfaToDfa(NFA A) {
    list<shared_ptr<State>> states = A.getStates();
    list<shared_ptr<State>> DStates;
//    list<set<shared_ptr<State>>> EqStates;
    queue<shared_ptr<State>> DQ;
    shared_ptr<State> s0 = setup(epsClosure(A.getStartState()));
    DStates.push_back(s0);
    DQ.push(s0);
//    EqStates.push_back(epsClosure(A.getStartState()));
    while (!DQ.empty()) {
        shared_ptr<State> t = DQ.front();
        DQ.pop();
        for (auto input = inputs.begin(); input != inputs.end(); ++input) {
            set<shared_ptr<State>> u = epsClosure(moveTo(t, *input));
            shared_ptr<State> s = setup(u);
            if (u.size() == 0) {
                continue;
            }
            shared_ptr<State> clone(new State(shared_ptr<Token>(new Token())));
            if (!checkD(DStates, s, &clone)) {
                DStates.push_back(s);
                DQ.push(s);
//                EqStates.push_back(u);
                t->resetTransion(*input, s);
            } else {
                t->resetTransion(*input, clone);
            }

        }
        t->getTrans().erase('0');
    }
    D.setStates(DStates);
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

// eps-closure for a single state
set<shared_ptr<State>> Controller::epsClosure(shared_ptr<State> state) {
    set<shared_ptr<State>> states;
    set<shared_ptr<State>> target;
    states.insert(state);
    auto temp = state->getTransion('0');
    for (auto it : temp) {
        target.insert(it);
        states.insert(it);
    }
    while (!target.empty()) {
        auto t = target.begin();
        if (*t == state) {
            target.erase(t);
            continue;
        }
        auto temp2 = t->operator->()->getTransion('0');
        for (auto it : temp2) {
            target.insert(it);
            states.insert(it);
        }
        target.erase(t);
    }
    return states;
}

// eps-closure for a set of states
set<shared_ptr<State>> Controller::epsClosure(set<shared_ptr<State>> states) {
    set<shared_ptr<State>> res;
    for (auto state : states) {
        res.insert(state);
        auto temp = epsClosure(state);
        res.insert(temp.begin(), temp.end());
    }
    return res;
}

// returns set of states reachable from given set of states on given input
set<shared_ptr<State>>
Controller::moveTo(set<shared_ptr<State>> states, char input) {
    set<shared_ptr<State>> res;
    for (auto state = states.begin(); state != states.end(); ++state) {
        set<shared_ptr<State>> temp = state->operator->()->getTransion(input);
        res.insert(temp.begin(), temp.end());
    }
    return res;
}

set<shared_ptr<State>>
Controller::moveTo(shared_ptr<State> state, char input) {
    set<shared_ptr<State>> res = state->getTransion(input);
    return res;
}

// creates a DFA state out of a set of states
shared_ptr<State> Controller::setup(set<shared_ptr<State>> states) {
    shared_ptr<State> dfaState(new State(shared_ptr<Token>(new Token())));
    for (auto state : states) {
        for (auto transition : state->getTrans())
            for (auto destination : transition.second)
                dfaState->setTransion(transition.first, destination);
        if (state->isEndState()) {
            dfaState->setEndState(true);
            dfaState->setToken(state->getToken());
        }
    }
//    unordered_map<char, set<shared_ptr<State>>> trans;
//    unordered_map<char, DFAState> trans2;
//    for (auto state : states) {
//        for (auto transitions : state->getTrans()) {
//            if (trans.count(transitions.first) > 0) {
//                auto temp = trans[transitions.first];
//                temp.insert(transitions.second.begin(),
//                            transitions.second.end());
//                trans.insert({transitions.first, temp});
//            } else {
//                set<shared_ptr<State>> temp;
//                temp.insert(transitions.second.begin(),
//                            transitions.second.end());
//                trans.insert({transitions.first, temp});
//            }
//        }
//    }
////    for (auto transition: trans) {
////        if (transition.first != '0') {
////            trans2.insert({transition.first, setup(transition.second)});
////        }
////    }
//    dfaState->setTrans(trans);
    dfaState->setEqStates(states);
    return dfaState;
}

bool Controller::checkD(list<shared_ptr<State>> list,
//                        std::list<set<shared_ptr<State>>> EqStates,
                        shared_ptr<State> state,
                        shared_ptr<State> *clone) {
    if (state->getTrans().size() == 0)
        return true;
    for (auto iter : list) {
        if(iter->getEqStates().size()!=state->getEqStates().size()) continue;
        bool answer = true;
        for (auto es : state->getEqStates()) {
            if (iter->getEqStates().count(es)<=0) {
                answer = false;
                break;
            }
        }
        if (!answer) continue;
        else {
            *clone = iter;
            return true;
        }
    }
    return false;
}

vector<char> Controller::getInputs() {
    return inputs;
}

void Controller::setInput(char input) {
    inputs.push_back(input);
}
