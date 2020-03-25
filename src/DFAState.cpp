//
// Created by zeny on 3/25/20.
//

#include "../include/DFAState.h"

DFAState::DFAState() {

}

bool DFAState::isEndState() {
    return false;
}

void DFAState::setEndState(bool end) {

}

set<State> DFAState::getTransion(char input) {
    return set<State>();
}

void DFAState::setTransion(char input, DFAState &e) {

}

void DFAState::setToken(shared_ptr<Token> t) {

}

shared_ptr<Token> DFAState::getToken() {
    return shared_ptr<Token>();
}
