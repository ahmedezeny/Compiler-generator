#include "../include/NFA.h"
#include <string.h>
#include <iostream>

using namespace std;

NFA::NFA()
{
    countOfStates = 0  ;
    //ctor
}

NFA::~NFA()
{
    //dtor
}



NFA::NFA(int number,shared_ptr<Token> token) : number(number),token(token) {
    countOfStates = 0  ;
}

int NFA::getNumber()
{
    return number;
}

void NFA::setNumber(int number)
{
    NFA::number = number;
}

shared_ptr<State> NFA::getStartState()
{
    return startState;
}

void NFA::setStartState( shared_ptr<State> startState)
{
    NFA::startState = startState;
}

shared_ptr<State> NFA::getEndState()
{
    return endState;
}

void NFA::setEndState(shared_ptr<State> endState)
{
    NFA::endState = endState;
}

list<shared_ptr<State>> NFA::getStates()
{
    return states;
}

void NFA::setStates( list<shared_ptr<State>> states)
{
    NFA::states = states;
}

shared_ptr<Token> NFA::getToken()
{
    return token;
}

void NFA::setToken( shared_ptr<Token> token)
{
    NFA::token = token;
}

NFA NFA::ast(NFA a1,shared_ptr<Token> token)
{
    shared_ptr<Token> t1 ( new Token(token->getName() + to_string(countOfStates) , token->getPattern() , token->getPriority() )) ;
    countOfStates++ ;
    string s = token->getName() + to_string(countOfStates) ;
    shared_ptr<Token> t2 ( new Token(s , token->getPattern() , token->getPriority()) );
    countOfStates++ ;


    NFA nfa = NFA(0,token);

    shared_ptr<State> strt (new State(t1));
    shared_ptr<State> endSS (new State(t2));

    strt->setTransion(0,endSS);
    endSS->setEndState(true);
    nfa.setStartState(strt);
    nfa.setEndState(endSS) ;
    shared_ptr<State> a1start = a1.getStartState();
    shared_ptr<State> a1end = a1.getEndState();
    strt->setTransion(0,a1start);
    a1end->setTransion(0,endSS);
    a1end->setTransion(0,a1start);
    a1end->setEndState(false);
    return nfa ;
}

NFA NFA::plusNFA(NFA a1,shared_ptr<Token> token)
{
    return concat(a1,ast(a1,token),token);
}

NFA NFA::concat(NFA a1, NFA a2,shared_ptr<Token> token)
{

    shared_ptr<Token> t1 ( new Token(token->getName() + to_string(countOfStates) , token->getPattern() , token->getPriority() )) ;
    countOfStates++ ;
    string s = token->getName() + to_string(countOfStates) ;
    shared_ptr<Token> t2 ( new Token(s , token->getPattern() , token->getPriority()) );
    countOfStates++ ;

    shared_ptr<State> strt (new State(t1));
    shared_ptr<State> endSS (new State(t2));


    NFA nfa = NFA(0,token);
    nfa.setStartState(a1.getStartState());
    /**
     *  predicted pointers problem
     * */
    shared_ptr<State> a1end = a1.getEndState();
    a1end->setEndState(false);
    a1end->setTransion(0,a2.getStartState());
    shared_ptr<State> a2end = a2.getEndState();
    a2end->setTransion(0,endSS);
    a2end->setToken(t1) ;
    nfa.setEndState(endSS);

    return nfa;
}

NFA NFA::oring(NFA a1, NFA a2,shared_ptr<Token> token)
{
    NFA nfa =NFA(0,token);



    shared_ptr<Token> t1 ( new Token(token->getName() + to_string(countOfStates) , token->getPattern() , token->getPriority() )) ;
    countOfStates++ ;
    string s = token->getName() + to_string(countOfStates) ;
    shared_ptr<Token> t2 ( new Token(s , token->getPattern() , token->getPriority()) );
    countOfStates++ ;


    shared_ptr<State> strt (new State(t1));
    shared_ptr<State> endSS (new State(t2));


    strt->setTransion(0,a1.getStartState());
    strt->setTransion(0,a2.getStartState());

    shared_ptr<State> a1end = a1.getEndState();
    shared_ptr<State> a2end = a2.getEndState();
    endSS->setEndState(true);
    a1end->setEndState(false) ;
    a2end->setEndState(false) ;
    a1end->setTransion(0,endSS);
    a2end->setTransion(0,endSS);


    nfa.setStartState(strt);
    nfa.setEndState(endSS);
    return nfa;
}

vector <string> NFA::parcingPattern ()
{

    vector <string > arg ;
    string s =  token->getName() ;
    string ns = "" ;
    for (int i = 0 ; i < s.size() ; i++)
    {
        if (s[i] == '|')
        {

        }
        else if (s[i] == '(')
        {

        }

        ns += s[i] ;
    }

    return arg;
}
NFA NFA::basicOp(string str,shared_ptr<Token> token)
{
    char c =str.at(0);
    if(c=='{')
    {

        return setOP(  str.substr(1,str.length()-2)  ,token);
    }
    else if(c=='[')
    {
        return intervalOP(str.substr(1,str.length()-2),token);
    }
    else
    {
        return charOP(c,token);
    }

}
NFA NFA::setOP( string str ,shared_ptr<Token>  token)
{
    shared_ptr<State>  strt (new State (token));
    NFA nfa (0,token);
    nfa.setStartState(strt);
    int i=0;
    shared_ptr<State>  endSS (new State (token));
    char c =str.at(0);
    while (c!='}')
    {
        c =str.at(i);
        if((c>='A'&&c<='Z')
                ||(c>='a'&&c<='z'))
        {
            strt->setTransion(c,endSS);
            i++;
        }
        else if(c==92)
        {
            i++;
            c =str.at(i);
            if(c=='*'||c=='+'||c=='?')
            {
                strt->setTransion(c,endSS);
            }
            i++;


        }
        else if(c==','||c==' ')
        {
            i++;
        }

    }
    endSS->setEndState(true);
    nfa.setEndState(endSS);
    return nfa;
}
NFA NFA::intervalOP(std :: string str,shared_ptr<Token>  token)
{
    shared_ptr<State>  strt (new State (token));
    NFA nfa (0,token);
    nfa.setStartState(strt);
    int i=0;
    shared_ptr<State>  endSS (new State (token));
    endSS->setEndState(true);
    nfa.setEndState(endSS);
    char c ;
    char b=0,e=0;
    while(c!=']')
    {
        c =str.at(i);
        if((c>='A'&&c<='Z')
                ||(c>='a'&&c<='z'))
        {
            if(b==0)
            {
                b=c;
            }
            else
            {
                e=c;
            }
            i++;
        }
        else if(c==92)
        {
            i++;
            c =str.at(i);
            if(c=='*'||c=='+'||c=='?')
            {
                if(b==0)
                {
                    b=c;
                }
                else
                {
                    e=c;
                }
            }
            i++;
        }
        else if(c=='-'||c==' ')
        {
            i++;
        }
    }
    i=0;
    c=b;
    while(c>=b && c<=e)
    {
        strt->setTransion(c,endSS);
        c++;
    }
    return nfa;
}
NFA NFA::charOP(char c,shared_ptr<Token>  token)
{
    shared_ptr<State>  strt (new State (token));
    NFA nfa (0,token);
    nfa.setStartState(strt);
    shared_ptr<State>  endSS (new State (token));
    strt->setTransion(c,endSS);
    endSS->setEndState(true);
    nfa.setEndState(endSS);

    return nfa ;
}
