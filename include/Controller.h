//
// Created by zeny on 3/24/20.
//

#ifndef COMPILER_CONTROLLER_H
#define COMPILER_CONTROLLER_H

#include "NFA.h"
#include "Token.h"
#include "DFA.h"
#include "DFAState.h"
#include <bits/stdc++.h>

class Controller {
private:
    vector<shared_ptr<Token>> tokens;
    vector<NFA> A;
    vector<char> inputs;
    NFA N;
    DFA D;

//    set<struct shared_ptr<State>> epsClosure(shared_ptr<State> s, char input);
//
//    set<shared_ptr<State>> epsClosure(set<shared_ptr<State>> s, char input);

//    shared_ptr<State> getUnMarked(unordered_map<set<shared_ptr<State>>, bool> &DStates);

public:
    Controller();

    virtual ~Controller();

    shared_ptr<Token> readToken(string rowToken, int priority);

    shared_ptr<Token> preProcess(vector<shared_ptr<Token>> tokens, int tokenNum);

    NFA oringAll(vector<NFA> A);

    DFA minDfa(DFA A);

    DFA nfaToDfa(NFA A);

    set<shared_ptr<State>> epsClosure(shared_ptr<State> state);

    shared_ptr<State> setup(set<shared_ptr<State>> states);

    set<shared_ptr<State>> moveTo(set<shared_ptr<State>> states, char input);

    set<shared_ptr<State>> moveTo(shared_ptr<State> state, char input);

    set<shared_ptr<State>> epsClosure(set<shared_ptr<State>> states);

    bool checkD(list<shared_ptr<State>> list/*, std::list<set<shared_ptr<State>>> EqStates*/, shared_ptr<State> state, shared_ptr<State> *clone);

    vector<char> getInputs();

    void setInput(char input);
};


#endif //COMPILER_CONTROLLER_H
