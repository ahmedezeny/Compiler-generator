#include "../include/NFA.h"
#include <string.h>
#include <iostream>

using namespace std;

NFA::NFA()
{
    //ctor
}

NFA::~NFA()
{
    //dtor
}

NFA::NFA(int number, shared_ptr<Token> token) : number(number), token(token)
{

    /*  string s = token->getPattern() ;
    NFA a =  intervalOP (s , token) ;
    cout << a.getStartState()->getToken()->getName() << endl ;
    cout << a.getStartState()->getToken()->getName() << endl ;
*/
}

int NFA::getNumber()
{
    return number;
}

void NFA::setNumber(int number)
{
    NFA::number = number;
}

shared_ptr<State> NFA::getStartState()
{
    return startState;
}

void NFA::setStartState(shared_ptr<State> startState)
{
    NFA::startState = startState;
}

shared_ptr<State> NFA::getEndState()
{
    return endState;
}

void NFA::setEndState(shared_ptr<State> endState)
{
    NFA::endState = endState;
}

list<shared_ptr<State>> NFA::getStates()
{
    return states;
}

void NFA::setStates(list<shared_ptr<State>> states)
{
    NFA::states = states;
}

NFA NFA::ast(NFA a1, shared_ptr<Token> token)
{
    shared_ptr<Token> t1(token);
    shared_ptr<Token> t2(token);

    NFA nfa = NFA(0, token);

    shared_ptr<State> strt(new State(t1));
    shared_ptr<State> endSS(new State(t2));

    strt->setTransion(0, endSS);
    endSS->setEndState(true);
    nfa.setStartState(strt);
    nfa.setEndState(endSS);
    shared_ptr<State> a1start = a1.getStartState();
    shared_ptr<State> a1end = a1.getEndState();
    strt->setTransion(0, a1start);
    a1end->setTransion(0, endSS);
    a1end->setTransion(0, a1start);
    a1end->setEndState(false);
    return nfa;
}

NFA NFA::plusNFA(NFA a1, shared_ptr<Token> token)
{
    return concat(a1, ast(a1, token), token);
}

NFA NFA::concat(NFA a1, NFA a2, shared_ptr<Token> token)
{

    shared_ptr<Token> t1(token);
    shared_ptr<Token> t2(token);

    shared_ptr<State> strt(new State(t1));
    shared_ptr<State> endSS(new State(t2));

    NFA nfa = NFA(0, token);
    nfa.setStartState(a1.getStartState());
    /**
     *  predicted pointers problem
     * */
    shared_ptr<State> a1end = a1.getEndState();
    a1end->setEndState(false);
    a1end->setTransion(0, a2.getStartState());
    shared_ptr<State> a2end = a2.getEndState();
    a2end->setTransion(0, endSS);
    a2end->setToken(t1);
    nfa.setEndState(endSS);

    return nfa;
}

NFA NFA::oring(NFA a1, NFA a2, shared_ptr<Token> token)
{
    NFA nfa = NFA(0, token);

    shared_ptr<Token> t1(token);
    shared_ptr<Token> t2(token);

    shared_ptr<State> strt(new State(t1));
    shared_ptr<State> endSS(new State(t2));

    strt->setTransion(0, a1.getStartState());
    strt->setTransion(0, a2.getStartState());

    shared_ptr<State> a1end = a1.getEndState();
    shared_ptr<State> a2end = a2.getEndState();
    endSS->setEndState(true);
    a1end->setEndState(false);
    a2end->setEndState(false);
    a1end->setTransion(0, endSS);
    a2end->setTransion(0, endSS);

    nfa.setStartState(strt);
    nfa.setEndState(endSS);
    return nfa;
}

NFA NFA::parcingPattern(set<shared_ptr<Token>> tokens)
{
    std::set<shared_ptr<Token>>::iterator it;
    for (it = tokens.begin(); it != tokens.end(); ++it)
   {
     shared_ptr<Token> token = *it;
     prevNFA[token->getName]=parcingOne(token->getPattern,token);
   }
    //parse all
}
NFA NFA::parcingOne(std::string str, shared_ptr<Token> token)
{
    // map prevNFA
    NFA nfa(0, token);
    shared_ptr<State> strt(new State(token));
    
    nfa.setStartState(strt);
    int i = 0;
    char c;
    int check = 0;
    std::string temp("");
    //| or symboll
    NFA nfaOrg(0, token);
    shared_ptr<State> strtOrg(new State(token));
    nfaOrg.setStartState(strtOrg);



    while (i < str.length)
    {
        check = 1;
        c = str.at(i);
        if (c == '(')
        {
            if (temp.length > 0)
            {
                nfa = charOP(temp, token);
                temp = string("");
            }
            i++;
            int stackN = 1;
            std::string s("");
            c = str.at(i);
            while (stackN > 0 && i < str.length)
            {
                if (c == ')')
                {
                    stackN--;
                }
                else if (i == '(')
                {
                    stackN++;
                }
                i++;
                if (stackN > 0)
                {
                    s.push_back(c);
                }
                if (i < str.length)
                {
                    c = str.at(i);
                }
            }
            if (s.length > 0)
            {
                nfa = concat(nfa, parcingOne(s, token), token);
            }
        }
        else if (c == '|')
        {
            check = 2;
            std::map<std::string, NFA>::iterator it;
            it = prevNFA.find(temp);
            if (it != prevNFA.end)
            {
                nfaOrg= oring(nfaOrg, it->second, token);
            }
            else
            {
                nfaOrg = oring(nfaOrg, parcingOne(temp, token), token);
            }
            temp = string("");
            NFA nfaOrg(0, token);
            shared_ptr<State> strtOrg(new State(token));
            nfaOrg.setStartState(strtOrg);
            i++;
        }
        else if (i > 0 && str.at(i - 1) != 92 && c == '*')
        {
            std::map<std::string, NFA>::iterator it;
            it = prevNFA.find(temp);
            if (it != prevNFA.end)
            {
                nfa = concat(nfa, ast(it->second, token), token);
            }
            else
            {
                if (temp.substr(temp.length - 2) != "")
                {
                    string ss = string("");
                    ss.push_back(c);
                    nfa = concat(ast(parcingOne(ss, token), token), parcingOne(temp, token), token);
                }
                else
                {
                    string ss = string("");
                    ss.push_back(c);
                    nfa = ast(parcingOne(ss, token), token);
                }
            }
        }
        else if (i > 0 && str.at(i - 1) != 92 && c == '+')
        {
            std::map<std::string, NFA>::iterator it;
            it = prevNFA.find(temp);
            if (it != prevNFA.end)
            {
                nfa = concat(nfa, plusNFA(it->second, token), token);
            }
            else
            {
                if (temp.substr(temp.length - 2) != "")
                {
                    string ss = string("");
                    ss.push_back(c);
                    nfa = concat(plusNFA(parcingOne(ss, token), token), parcingOne(temp, token), token);
                }
                else
                {
                    string ss = string("");
                    ss.push_back(c);
                    nfa = plusNFA(parcingOne(ss, token), token);
                }
            }
        }
        else if (i > 0 &&i+1<str.length&&str.at(i - 1) != 92 && c!='-')
        {
            char b =str.at(i-1);
            char e =str.at(i+1);
            if((b>='A'&&b<='Z'&&e>='A'&&e<='Z')
            ||(b>='a'&&b<='z'&&e>='a'&&e<='z')
            ||(b>='0'&&b<='9'&&e>='0'&&e<='9'))
            {
            if(check!=2)
            {
                nfa =concat(nfa,intervalOP(b,c,token),token);
            }
            else
            {
                nfaOrg=oring(nfaOrg,intervalOP(b,c,token),token);
            }      
            }
            
        }
        else if(c!=' ')
        {
            temp.push_back(c);
        }
        i++;
    }
    if (temp.length > 0)
    {
        std::map<std::string, NFA>::iterator it;
        it = prevNFA.find(temp);
        if (it != prevNFA.end)
        {
            nfa = concat(nfa, it->second, token);
        }
        else
        {
            nfa = concat(nfa, parcingOne(temp, token), token);
        }
        if(check==2)
        {
            nfa = oring(nfaOrg,nfa,token);
        }
    }
    return nfa;
}


NFA NFA::intervalOP(char b,char e, shared_ptr<Token> token)
{
    shared_ptr<State> strt(new State(token));
    NFA nfa(0, token);
    nfa.setStartState(strt);
    int i = 0;
    shared_ptr<State> endSS(new State(token));
    endSS->setEndState(true);
    nfa.setEndState(endSS);
    char c;
    i = 0;
    c = b;
    while (c >= b && c <= e)
    {
        strt->setTransion(c, endSS);
        c++;
    }
    return nfa;
}
NFA NFA::charOP(std::string str, shared_ptr<Token> token)
{
    shared_ptr<State> strt(new State(token));
    NFA nfa(0, token);
    nfa.setStartState(strt);
    shared_ptr<State> next(new State(token));
    char c;
    int i = 0;
    while (i < str.length)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            next = shared_ptr<State>(new State(token));
            strt->setTransion(c, next);
            strt = next;
            i++;
        }
        else if (c == 92 && i + 1 < str.length)
        {
            i++;
            if ((c >= 40 && c <= 43) || (c >= 91 && c <= 94) || c == 46 || c == 63 || c == 124)
            {
                next = shared_ptr<State>(new State(token));
                strt->setTransion(c, next);
                strt = next;
                i++;
            }
        }
        else
        {
            //error
        }
    }
    strt->setEndState(true);
    nfa.setEndState(strt);

    return nfa;
}
