#ifndef STATE_H
#define STATE_H

#include <bits/stdc++.h>
#include "Token.h"
#include <memory>

using namespace std;


class State {
public:
    State();

    virtual ~State();

    State(shared_ptr<Token> stateToken);

    bool isEndState();

    void setEndState(bool end);

    void setTransion(char input, shared_ptr<State> e);

    void resetTransion(char input, shared_ptr<State> e);

    set<shared_ptr<State>> getTransion(char input);

    unordered_map<char, set<shared_ptr<State>>> getTrans();

    void setToken(shared_ptr<Token> t);

    shared_ptr<Token> getToken();

    void setEqStates(set<shared_ptr<State>> states);

    set<shared_ptr<State>> getEqStates();

    unordered_map<char, set<shared_ptr<State>>> getAllT();

    friend bool operator<(const State &left, const State &right);

    friend bool operator==(const State &left, const State &right);

protected:

private:
    unordered_map<char, set<shared_ptr<State>>> trans;
    bool endState;
    shared_ptr<Token> stateToken;
    set<shared_ptr<State>> EqStates;
};

ostream &operator<(ostream &output, const State &H);

ostream &operator==(ostream &output, const State &H);

#endif // STATE_H