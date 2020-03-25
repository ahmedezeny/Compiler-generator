//
// Created by zeny on 3/25/20.
//

#ifndef COMPILER2_DFASTATE_H
#define COMPILER2_DFASTATE_H

#include "State.h"
#include "Token.h"
class DFAState{

public:
DFAState();
bool isEndState () ;
void setEndState ( bool end ) ;

void setTransion ( char input , DFAState &e);
set<State> getTransion ( char input) ;
void setToken ( shared_ptr<Token> t) ;
shared_ptr<Token> getToken ();

private:
unordered_map <char,set<shared_ptr<State>>> trans;
set<shared_ptr<State>> equalState;
bool endState;
shared_ptr<Token>  stateToken;
};

#endif //COMPILER2_DFASTATE_H
