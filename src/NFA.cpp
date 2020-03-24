#include "../include/NFA.h"

NFA::NFA()
{
    //ctor
}

NFA::~NFA()
{
    //dtor
}



NFA::NFA(int number,Token token) : number(number),token(token) {}

int NFA::getNumber()  {
    return number;
}

void NFA::setNumber(int number) {
    NFA::number = number;
}

 State &NFA::getStartState()  {
    return startState;
}

void NFA::setStartState( State &startState) {
    NFA::startState = startState;
}

 State &NFA::getEndState()  {
    return endState;
}

void NFA::setEndState( State &endState) {
    NFA::endState = endState;
}

list<State> &NFA::getStates()  {
    return states;
}

void NFA::setStates( list<State> &states) {
    NFA::states = states;
}

Token &NFA::getToken()  {
    return token;
}

void NFA::setToken( Token &token) {
    NFA::token = token;
}

NFA NFA::ast(NFA a1, Token e) {
    //todo
    return NFA(0, Token());
}

NFA NFA::plusNFA(NFA a1, Token e) {
    //todo
    return NFA(0, Token());
}

NFA NFA::concat(NFA a1, NFA a2 , Token e) {
    //todo
    return NFA(0, Token());
}

NFA NFA::oring(NFA a1, NFA a2 , Token e) {
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
