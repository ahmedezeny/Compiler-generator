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
        vector<Token> tokens;
        vector<NFA> A;
        NFA N;
        DFA D;
    public:
        Controller();
        Token readToken(string rowToken,int priority);
        Token preProcess(vector<Token> tokens, int tokenNum);
        NFA oringAll(vector<NFA> A);
        DFA minDfa (DFA A);
        DFA nfaToDfa (NFA A);

};


#endif //COMPILER_CONTROLLER_H
