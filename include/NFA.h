#ifndef NFA_H
#define NFA_H

#include "State.h"
#include "Token.h"

class NFA {
    public:
        NFA();

        virtual ~NFA();

        NFA(int number, Token token);

        int getNumber();

        void setNumber(int number);

        State &getStartState();

        void setStartState(State &startState);

        State &getEndState();

        void setEndState(State &endState);

        list<State> &getStates();

        void setStates(list<State> &states);

        Token &getToken();

        void setToken(Token &token);


    protected:

    private:
        int number; // we may remove that
        State startState;
        State endState;
        list<State> states;
        Token token;
        bool marked = false;
        NFA ast(NFA a1, Token t);

        NFA plusNFA(NFA a1, Token t);

        NFA concat(NFA a1, NFA a2, Token t);

        NFA oring(NFA a1, NFA a2, Token t);

        vector<string> parcingPattern();

};

#endif // NFA_H
