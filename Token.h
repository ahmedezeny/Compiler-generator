//
// Created by zeny on 3/23/20.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H

class Token {

    char* name;
    char* pattern;
    int priority;
public:
    Token(char *name);

    Token(char *name, char *pattern, int priority);

    

    char *getName() const;

    void setName(char *name);

    char *getPattern() const;

    void setPattern(char *pattern);

    int getPriority() const;

    void setPriority(int priority);


};



#endif //COMPILER_TOKEN_H
