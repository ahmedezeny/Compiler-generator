//
// Created by zeny on 3/24/20.
//

#include "Controller.h"

Controller::Controller() {

}

Token Controller::readToken(string rowToken, int priority) {
    return Token();
}

Token Controller::preProcess(vector<Token> tokens, int tokenNum) {
    return Token();
}

DFA Controller::nfaToDfa(NFA A) {
    list<State> states = A.getStates();
    unordered_map<set<State>, bool> DStates;
    unordered_map<set<State>, bool> DTran;
    set<State> s0 = epsClosure(A.getStartState(), '0');
    DStates.insert({s0, false});
    State t = getUnMarked(DStates);
    while (t.getToken().getName() != NULL) {
        for (auto i = t.getTrans().begin(); i != t.getTrans().end(); ++i) {
            char input = i->first;
            set<State> u = epsClosure(epsClosure(t, input), '0');
            if (!checkD(u)) {
                DStates.insert({u, false});
            }
        }
        State t = getUnMarked(DStates);
    }
    return DFA();
}

DFA Controller::minDfa(DFA A) {
    return DFA();
}

NFA Controller::oringAll(vector<NFA> A) {
    NFA *nfa;
    State *newStartState;
    vector<NFA>::iterator it;
    for (it = A.begin(); it != A.end(); it++) {
        newStartState->setTransion('\0', it->getStartState());
        it->setStartState(*newStartState);
    }
    return *nfa;
}

set<State> Controller::epsClosure(State s, char input) {
    return s.getTransion(input);
}

set<State> Controller::epsClosure(set<State> s, char input) {
    set<State> res;
    for (auto it = s.begin(); it != s.end(); ++it) {
        set<State> temp = epsClosure(*it, input);
        res.insert(temp.begin(), temp.end());
    }
    return s;
}

State Controller::getUnMarked(unordered_map<set<State>, bool> &DStates) {
    auto iterator = DStates.begin();
    while (iterator != DStates.end()) {
        if(!iterator->second)
            return iterator->first;
    }
    return static_cast<State>(static_cast<Token>(nullptr));
}


