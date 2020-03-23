//
// Created by zeny on 3/23/20.
//

#include "State.h"
#include "Token.h"

State::State(const Token &stateToken) : stateToken(stateToken) {}

State::State(const list<map<char,set<State>>>, bool endState, const Token &stateToken):

trans (trans), endState(endState), stateToken(stateToken) {}

