#ifndef STATE_H
#define STATE_H

#include <bits/stdc++.h>
#include "Token.h"
#include <memory>

using namespace std;


class State
{
    public:
        State();
        virtual ~State();
        State(  shared_ptr<Token> stateToken);
        bool isEndState () ;
        void setEndState ( bool end ) ;
        void setTransion ( char input , shared_ptr<State> e);
        set<shared_ptr<State>> getTransion ( char input) ;
        void setToken ( shared_ptr<Token> t) ;
        shared_ptr<Token> getToken ();
        friend bool operator< (const State &left, const State &right);
        friend bool operator== (const State &left, const State &right);
    protected:

    private:
        unordered_map <char,set<shared_ptr<State>>> trans;
        bool endState;
        shared_ptr<Token>  stateToken;

};

std::ostream& operator<(std::ostream& output, const State& H);
std::ostream& operator==(std::ostream& output, const State& H);
#endif // STATE_H
