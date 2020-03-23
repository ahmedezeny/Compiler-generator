//
// Created by zeny on 3/23/20.
//

#include "NFA.h"
#include "State.h"
#include "Token.h"
NFA::NFA(int number,Token token) : number(number),token(token) {}

int NFA::getNumber() const {
    return number;
}

void NFA::setNumber(int number) {
    NFA::number = number;
}

const State &NFA::getStartState() const {
    return startState;
}

void NFA::setStartState(const State &startState) {
    NFA::startState = startState;
}

const State &NFA::getEndState() const {
    return endState;
}

void NFA::setEndState(const State &endState) {
    NFA::endState = endState;
}

const list<State> &NFA::getStates() const {
    return states;
}

void NFA::setStates(const list<State> &states) {
    NFA::states = states;
}

const Token &NFA::getToken() const {
    return token;
}

void NFA::setToken(const Token &token) {
    NFA::token = token;
}
