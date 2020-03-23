//
// Created by zeny on 3/24/20.
//

#ifndef COMPILER_CONTROLLER_H
#define COMPILER_CONTROLLER_H

#include "NFA.h"
#include "Token.h"

class Controller {
    private:
        vector<Token> tokens;
        vector<NFA> A;
    public:
        Controller();
        Token readToken(string rowToken,int priority);
        Token preProcess(vector<Token> tokens, int tokenNum);
        //DFA NfaToDfa (NFA A); //after creating DFA Class

};


#endif //COMPILER_CONTROLLER_H
