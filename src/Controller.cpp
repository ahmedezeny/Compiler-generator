//
// Created by zeny on 3/24/20.
//

#include "Controller.h"
Controller::Controller(){

}

Token Controller::readToken(string rowToken, int priority) {
    return Token();
}

Token Controller::preProcess(vector<Token> tokens, int tokenNum) {
    return Token();
}

DFA Controller::nfaToDfa(NFA A) {
    return DFA();
}

DFA Controller::minDfa(DFA A) {
    return DFA();
}

NFA Controller::oringAll(vector<NFA> A) {
    NFA *nfa;
    State *newStartState;
    vector<NFA>::iterator it;
    for(it=A.begin();it!=A.end();it++){
        newStartState->setTransion('\0', it->getStartState());
        it->setStartState(*newStartState);
    }
    return *nfa;
}


