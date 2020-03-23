//
// Created by zeny on 3/23/20.
//

#include "Token.h"

Token::Token(char *name) : name(name) {}

Token::Token(char *name, char *pattern, int priority) : name(name), pattern(pattern), priority(priority) {}
char *Token::getName() const {
    return name;
}

void Token::setName(char *name) {
    Token::name = name;
}

char *Token::getPattern() const {
    return pattern;
}

void Token::setPattern(char *pattern) {
    Token::pattern = pattern;
}

int Token::getPriority() const {
    return priority;
}

void Token::setPriority(int priority) {
    Token::priority = priority;
}