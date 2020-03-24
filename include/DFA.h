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
};


#endif //COMPILER_DFA_H
