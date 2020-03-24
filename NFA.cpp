//
// Created by zeny on 3/23/20.
//

#include "NFA.h"
#include "State.h"
#include "Token.h"

NFA::NFA(int number,Token token) : number(number),token(token) {}

int NFA::getNumber()  {
    return number;
}

void NFA::setNumber(int number) {
    NFA::number = number;
}

State &NFA::getStartState() {
    return startState;
}

void NFA::setStartState( State &startState) {
    NFA::startState = startState;
}

State &NFA::getEndState() {
    return endState;
}

void NFA::setEndState( State &endState) {
    NFA::endState = endState;
}

list<State> &NFA::getStates() {
    return states;
}

void NFA::setStates( list<State> &states) {
    NFA::states = states;
}

Token &NFA::getToken() {
    return token;
}

void NFA::setToken( Token &token) {
    NFA::token = token;
}

NFA NFA::ast(NFA a1, NFA a2) {
    //todo
    return NFA(0, Token());
}

NFA NFA::plus(NFA a1, NFA a2) {
    //todo
    return NFA(0, Token());
}

NFA NFA::concat(NFA a1, NFA a2) {
    //todo
    return NFA(0, Token());
}

NFA NFA::oring(NFA a1, NFA a2) {
    //todo
    return NFA(0, Token());
}

 vector <string> NFA::parcingPattern () {

     vector <string > arg ;
     string s =  token.getName() ;
     string ns = "" ; 
     for (int i = 0 ; i < s.size() ; i++) {
        if (s[i] == '|'){
             arg.push_back(ns);
             ns = "" ; 
        } else if (s[i] == '(') {

        }else if (s[i] = ' ' ){
            continue ; 
        }

        ns += s[i] ; 
     }

     return arg;
 }
