#include "DFA.h"
#include <bits/stdc++.h>

DFA::DFA()
{
    //ctor
}

list <shared_ptr<State>> DFA::getStates(){
    return states;
}

void DFA::setStates(list<shared_ptr<State>> states) {
    DFA::states = states;
}

shared_ptr<State> DFA::getEndState() {
    return DFA::endState;
}

void DFA::setEndState(shared_ptr<State> endstate) {
    DFA::endState = endstate;
}


