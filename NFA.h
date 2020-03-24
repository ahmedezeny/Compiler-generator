//
// Created by zeny on 3/23/20.
//

#ifndef COMPILER_NFA_H
#define COMPILER_NFA_H
#include <bits/stdc++.h>
#include <vector> 
#include <string> 
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
        vector <string> parcingPattern () ;

    public:
        NFA();

        NFA(int number,Token token);

        int getNumber() ;

        void setNumber(int number);

        State &getStartState() ;

        void setStartState( State &startState);

        State &getEndState() ;

        void setEndState(State &endState);

        list<State> &getStates();

        void setStates(list<State> &states);

        Token &getToken();

        void setToken(Token &token);

};



#endif //COMPILER_NFA_H
