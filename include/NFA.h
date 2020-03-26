#ifndef NFA_H
#define NFA_H

#include "State.h"
#include "Token.h"
#include <memory>

class NFA {
public:
    NFA();

    virtual ~NFA();

    NFA(int number, shared_ptr<Token> token);

    int getNumber();

    void setNumber(int number);

    shared_ptr<State> getStartState();

    void setStartState(shared_ptr<State> startState);

    shared_ptr<State> getEndState();

    void setEndState(shared_ptr<State> endState);

    list<shared_ptr<State>> getStates();

    void setStates(list<shared_ptr<State>> states);


    NFA intervalOP(string str,shared_ptr<Token>  token);
    protected:

    private:
        int number; // we may remove that
        shared_ptr<State> startState;
        shared_ptr<State> endState;
        list <shared_ptr<State>> states;
        shared_ptr<Token> token;
        std::map<std::string ,NFA>  prevNFA;

        NFA ast(NFA a1 , shared_ptr<Token> t);
        NFA plusNFA(NFA a1, shared_ptr<Token> t);
        NFA concat(NFA a1,NFA a2 , shared_ptr<Token> t );
        NFA oring(NFA a1,NFA a2 , shared_ptr<Token> t);
        NFA charOP(std::string str,shared_ptr<Token>  token);
        NFA intervalOP(char b,char e, shared_ptr<Token> token);
 
        NFA parcingPattern (std::set<shared_ptr<Token>> tokens) ;
        NFA parcingOne (std::string str,shared_ptr<Token> token) ;

};

#endif // NFA_H
