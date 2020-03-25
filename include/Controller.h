//
// Created by zeny on 3/24/20.
//

#ifndef COMPILER_CONTROLLER_H
#define COMPILER_CONTROLLER_H

#include "NFA.h"
#include "Token.h"
#include "DFA.h"

class Controller {
private:
    vector<shared_ptr<Token>> tokens;
    vector<NFA> A;
    NFA N;
    DFA D;

    set<struct shared_ptr<State>> epsClosure(shared_ptr<State> s, char input);

    set<shared_ptr<State>> epsClosure(set<shared_ptr<State>> s, char input);

    shared_ptr<State> getUnMarked(unordered_map<set<shared_ptr<State>>, bool> &DStates);

public:
    Controller();

    virtual ~Controller();

    shared_ptr<Token> readToken(string path);

    shared_ptr<Token> preProcess(vector<shared_ptr<Token>> tokens, int tokenNum);

    NFA oringAll(vector<NFA> A);

    DFA minDfa(DFA A);

    DFA nfaToDfa(NFA A);


    bool checkD(set<shared_ptr<State>> set);
};


#endif //COMPILER_CONTROLLER_H
