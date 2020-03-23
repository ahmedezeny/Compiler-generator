//
// Created by zeny on 3/23/20.
//

#ifndef COMPILER_NFA_H
#define COMPILER_NFA_H
#include <bits/stdc++.h>
#include "State.h"
#include "Token.h"
using namespace std;

class NFA {

    private:
        int number; // we may remove that
        State startState;
        State endState;
        list <State> states;
        Token token;

        NFA ast(NFA a1,NFA a2);
        NFA plus(NFA a1,NFA a2);
        NFA concat(NFA a1,NFA a2);
        NFA oring(NFA a1,NFA a2);

    public:
        NFA(int number,Token token);

        int getNumber() const;

        void setNumber(int number);

        const State &getStartState() const;

        void setStartState(const State &startState);

        const State &getEndState() const;

        void setEndState(const State &endState);

        const list<State> &getStates() const;

        void setStates(const list<State> &states);

        const Token &getToken() const;

        void setToken(const Token &token);

};



#endif //COMPILER_NFA_H
