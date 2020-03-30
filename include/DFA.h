//
// Created by zeny on 3/24/20.
//

#ifndef COMPILER_DFA_H
#define COMPILER_DFA_H


#include "State.h"

class DFA {
    private:
        int number; // we may remove that
        State startState;
        State endState;
        list <State> states;
    public:
    DFA();

    int getNumber() const;

    void setNumber(int number);

    const State &getStartState() const;

    void setStartState(const State &startState);

    const State &getEndState() const;

    void setEndState(const State &endState);

    const list<State> &getStates() const;

    void setStates(const list<State> &states);
};


#endif //COMPILER_DFA_H
