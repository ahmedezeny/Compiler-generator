#ifndef STATE_H
#define STATE_H

#include <bits/stdc++.h>
#include "Token.h"

using namespace std;


class State
{
    public:
        State();
        virtual ~State();
        State(Token stateToken);
        bool isEndState () ;
        void setEndState ( bool end ) ;
        void setTransion ( char input , State &e);
        set<State> getTransion ( char input) ;
        void setToken (Token t) ;
        Token getToken ();
        friend bool operator< (const State &left, const State &right);

    protected:

    private:
        unordered_map <char,set<State>> trans;
        bool endState;
        Token stateToken;

};

std::ostream& operator<(std::ostream& output, const State& H);

#endif // STATE_H
