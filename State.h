//
// Created by zeny on 3/23/20.
//

#ifndef COMPILER_STATE_H
#define COMPILER_STATE_H
#include <bits/stdc++.h>
#include "Token.h"

using namespace std;

class State {
private:
    unordered_map <char,set<State>> trans;
    bool endState;
    Token stateToken;

public:
    State();

    State(const Token &stateToken);

    State(const unordered_map<char,set<State>> , bool endState, const Token &stateToken);

    bool isEndState () ;

    void setEndState ( bool end ) ; 

    void setTransion ( char input , State e);

    set<State> getTransion ( char input) ; 

    void setToken (Token t) ; 

    Token getToken (); 

};


#endif //COMPILER_STATE_H
