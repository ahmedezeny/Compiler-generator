//
// Created by zeny on 3/23/20.
//

#include "Token.h"

Token::Token(string name) : name(name) {}

Token::Token(string name, string pattern, int priority) : name(name), pattern(pattern), priority(priority) {}
string Token::getName() const {
    return name;
}

void Token::setName(string name) {
    Token::name = name;
}

string Token::getPattern() const {
    return pattern;
}

void Token::setPattern(string pattern) {
    Token::pattern = pattern;
}

int Token::getPriority() const {
    return priority;
}

void Token::setPriority(int priority) {
    Token::priority = priority;
}