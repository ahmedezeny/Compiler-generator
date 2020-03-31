//
// Created by zeny on 3/24/20.
//

#include "Controller.h"
#include <bits/stdc++.h>
#include <DFAState.h>

Controller::Controller() {

}

Controller::~Controller() {

}

shared_ptr<Token> Controller::readToken(string rowToken, int priority) {
    return shared_ptr<Token>();
}

shared_ptr<Token>
Controller::preProcess(vector<shared_ptr<Token>> tokens, int tokenNum) {
    return shared_ptr<Token>();
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
            if (!checkD(DStates/*, EqStates*/, s, &clone)) {
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

DFA Controller::minDfa(DFA A) {
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


