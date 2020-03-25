#include "../include/State.h"
#include "../include/Token.h"
#include <memory>

State::State() {
    //ctor
}

State::~State() {
    //dtor
}

State::State(shared_ptr<Token> stateToken) : stateToken(stateToken) {
    //cout << State::stateToken->getName() << "gg\n";
    endState = false;
}


bool State::isEndState() {
    return endState;
}


void State::setTransion(char input, shared_ptr<State> e) {
    if (trans[input].find(e) == trans[input].end()) {
        trans[input].insert(e);
    } else {
        cout << "error" << endl;
    }
}


set<shared_ptr<State>> State::getTransion(char input) {

    if (trans.find(input) == trans.end()) {
        set<shared_ptr<State>> s;
        return s;
    }

    return trans[input];
}

void State::setEndState(bool end) {
    endState = end;
}

void State::setToken(shared_ptr<Token> t) {
    stateToken = t;
}

shared_ptr<Token> State::getToken() {

    return stateToken;
}


bool operator<(const State &left, const State &right) {
    State l = left;
    State r = right;

    return l.getToken()->getName() < r.getToken()->getName();
}


/*
bool operator< (const State &left, const State &right)
{

    return reinterpret_cast<const char*>( std::addressof(left) ) < reinterpret_cast<const char*>( std::addressof(right) ) ;
}

bool operator== (const State &left, const State &right)
{

    return reinterpret_cast<const char*>( std::addressof(left) ) == reinterpret_cast<const char*>( std::addressof(right) );
}
*/

unordered_map<char, set<shared_ptr<State>>> State::getTrans() {
    return trans;
}

/*bool operator< ( State &left,  State &right)
{
    return left.getToken().getName() < right.getToken().getName();
}*/
/*bool operator< (const Point2D &right) const
{
    return etToken().getName() < right.getToken().getName();
}*/
