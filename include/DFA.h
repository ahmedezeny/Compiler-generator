//
// Created by zeny on 3/24/20.
//

#ifndef COMPILER_DFA_H
#define COMPILER_DFA_H


#include "State.h"
#include "DFAState.h"
#include <bits/stdc++.h>

class DFA {
public:
    DFA();

    int getNumber() const;

    void setNumber(int number);

    shared_ptr<State> getStartState() const;

    void setStartState(shared_ptr<State> startState);

    shared_ptr<State> getEndState() const;

    void setEndState(shared_ptr<State> endState);

    list<shared_ptr<State>> getStates() const;

    void setStates(list<shared_ptr<State>> states);
    
private:
    int number; // we may remove that
    shared_ptr<State> startState;
    shared_ptr<State> endState;
    list<shared_ptr<State>> states;
};


#endif //COMPILER_DFA_H
