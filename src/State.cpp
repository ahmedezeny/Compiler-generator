#include "../include/State.h"
#include "../include/Token.h"

State::State()
{
    //ctor
}

State::~State()
{
    //dtor
}

State::State( Token stateToken) : stateToken(stateToken)
{
    cout << stateToken.getName()  << "gg\n";
    endState = false ;
}


bool State::isEndState ()
{
    return endState ;
}


void State::setTransion ( char input, State &e)
{
    cout << e.getToken().getName() << " ff" << endl ;
    trans[input].insert(e) ;
}


set<State> State::getTransion(char input )
{

    if (trans.find(input) == trans.end())
    {
        set<State> s ;
        return s ;
    }

    return trans[input];
}

void State::setEndState ( bool end )
{
    endState = end ;
}

void State::setToken (Token t)
{
    stateToken = t ;
}

Token State::getToken()
{

    return stateToken ;
}

bool operator< (const State &left, const State &right)
{
    State l = left ;
    State r = right ;

    return l.getToken().getName() < r.getToken().getName();
}

unordered_map<char, set<State>> State::getTrans() {
    return unordered_map<char, set<State>>();
}

/*bool operator< ( State &left,  State &right)
{
    return left.getToken().getName() < right.getToken().getName();
}*/
/*bool operator< (const Point2D &right) const
{
    return etToken().getName() < right.getToken().getName();
}*/
