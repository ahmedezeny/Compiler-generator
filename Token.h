//
// Created by zeny on 3/23/20.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H

#include <bits/stdc++.h>
using namespace std;

class Token {

    string name;
    string pattern;
    int priority;
public:
    Token(string name);

    Token(string name, string pattern, int priority);



    string getName() const;

    void setName(string name);

    string getPattern() const;

    void setPattern(string pattern);

    int getPriority() const;

    void setPriority(int priority);


};



#endif //COMPILER_TOKEN_H
