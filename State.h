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
    list<map<char,set<State>>> trans;
    bool endState;
    Token stateToken;

public:
    State();

    State(const Token &stateToken);

    State(const list<map<char,set<State>>>, bool endState, const Token &stateToken);


};


#endif //COMPILER_STATE_H
