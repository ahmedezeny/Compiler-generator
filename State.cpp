//
// Created by zeny on 3/23/20.
//

#include "State.h"
#include "Token.h"

State::State(const Token &stateToken) : stateToken(stateToken) {
   endState = false ; 
}

State::State(const unordered_map<char,set<State>> , bool endState, const Token &stateToken):

trans (trans), endState(endState), stateToken(stateToken) {}

 bool State::isEndState () {
    return endState ;
 }


void State::setTransion ( char input , State e) {
   trans[input].insert(e) ; 
}


set<State> State::getTransion(char input ) {
    
     if (trans.find(input) == trans.end()){
        set<State> s ; 
        return s ;  
     }

     return trans[input]; 
}

void State::setEndState ( bool end ){
        endState = end ; 
}

void State::setToken (Token t) {
     stateToken = t ; 
} 

Token State::getToken(){
  return stateToken ; 
} 