#include "../include/DFA.h"

DFA::DFA()
{
    //ctor
}

int DFA::getNumber() const {
    return number;
}

void DFA::setNumber(int number) {
    DFA::number = number;
}

const State &DFA::getStartState() const {
    return startState;
}

void DFA::setStartState(const State &startState) {
    DFA::startState = startState;
}

const State &DFA::getEndState() const {
    return endState;
}

void DFA::setEndState(const State &endState) {
    DFA::endState = endState;
}

const list<State> &DFA::getStates() const {
    return states;
}

void DFA::setStates(const list<State> &states) {
    DFA::states = states;
}
