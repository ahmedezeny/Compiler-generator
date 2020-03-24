#include "../include/NFA.h"

NFA::NFA()
{
    //ctor
}

NFA::~NFA()
{
    //dtor
}



NFA::NFA(int number,Token token) : number(number),token(token) {}

int NFA::getNumber()  {
    return number;
}

void NFA::setNumber(int number) {
    NFA::number = number;
}

 State &NFA::getStartState()  {
    return startState;
}

void NFA::setStartState( State &startState) {
    NFA::startState = startState;
}

 State &NFA::getEndState()  {
    return endState;
}

void NFA::setEndState( State &endState) {
    NFA::endState = endState;
}

list<State> &NFA::getStates()  {
    return states;
}

void NFA::setStates( list<State> &states) {
    NFA::states = states;
}

Token &NFA::getToken()  {
    return token;
}

void NFA::setToken( Token &token) {
    NFA::token = token;
}

 NFA NFA::ast(NFA a1,Token token) {

    NFA nfa =NFA(0,token);

    State strt =State(token);
    State end=State(Token());

    strt.setTransion(0,end);
    end.setEndState(true);
    nfa.setStartState(strt);

    State a1start =a1.getStartState;
    State a1end =a1.getEndState;
    a1end.setTransion(0,end);
    a1end.setTransion(0,a1start);
    a1end.setEndState(false);
    return nfa ;
}

NFA NFA::plus(NFA a1,Token token) {
    return concat(a1,ast(a1,token),token);
}

NFA NFA::concat(NFA a1, NFA a2,Token token) {

    NFA nfa =NFA(0,token);
    nfa.setStartState(a1.getStartState);
    /**
     *  predicted pointers problem
     * */
    State a1end=a1.getEndState;
    a1end.setEndState(false);
    a1end.setTransion(0,a2.getStartState);
    nfa.setEndState(a2.getEndState);

    return nfa;
}

NFA NFA::oring(NFA a1, NFA a2,Token token) {
    NFA nfa =NFA(0,token);

    State strt =State(token);
    State end=State(token);
    strt.setTransion(0,a1.getStartState);
    strt.setTransion(0,a2.getStartState);

    State a1end=a1.getEndState;
    State a2end=a2.getEndState;
    a1end.setTransion(0,end);
    a2end.setTransion(0,end);

    end.setEndState(true);
    nfa.setStartState(strt);
    nfa.setEndState(end);
    return nfa;
}

 vector <string> NFA::parcingPattern () {

     vector <string > arg ;
     string s =  token.getName() ;
     string ns = "" ;
     for (int i = 0 ; i < s.size() ; i++) {
        if (s[i] == '|'){

        } else if (s[i] == '(') {

        }

        ns += s[i] ;
     }

     return arg;
 }
NFA NFA::basicOp(std ::string str,Token token)
{
     char c =str.at(0);
     if(c=='{')
     {
         return setOP(str.substr(1,str.length-2),token);
     }
     else if(c=='[')
     {
         return intervalOP(str.substr(1,str.length-2),token);
     }
     else
     {
         return charOP(c,token);
     }

}
NFA NFA::setOP(std :: string str,Token token)
{
  State strt (token);
  NFA nfa (0,token);
  nfa.setStartState(strt);
  int i=0;
  State end (token);
  char c =str.at(0);
  while (c!='}')
  {
      c =str.at(i);
      if((c>='A'&&c<='Z')
      ||(c>='a'&&c<='z'))
      {
        strt.setTransion(c,end);
        i++;
      }
      else if(c==92)
      {
         i++;
         c =str.at(i);
         if(c=='*'||c=='+'||c=='?')
         {
             strt.setTransion(c,end);
         }
         i++;


      }
      else if(c==','||c==' ')
      {
          i++;
      }

  }
  end.setEndState(true);
  nfa.setEndState(end);
}
NFA NFA::intervalOP(std :: string str,Token token)
{
  State strt (token);
  NFA nfa (0,token);
  nfa.setStartState(strt);
  int i=0;
  State end (token);
  end.setEndState(true);
  nfa.setEndState(end);
  char c ;
  char b=0,e=0;
  while(c!=']')
  {
    c =str.at(i);
    if((c>='A'&&c<='Z')
      ||(c>='a'&&c<='z'))
      {
          if(b==0)
          {
              b=c;
          }
          else
          {
              e=c;
          }
          i++;
      }
      else if(c==92)
      {
         i++;
         c =str.at(i);
         if(c=='*'||c=='+'||c=='?')
         {
          if(b==0)
          {
              b=c;
          }
          else
          {
              e=c;
          }
         }
         i++;
      }
      else if(c=='-'||c==' ')
      {
          i++;
      }
  }
  i=0;
  c=b;
  while(c>=b&&c<=e)
  {
     strt.setTransion(c,end);
     c++;
  }
}
NFA NFA::charOP(char c,Token token)
{
      State strt (token);
      NFA nfa (0,token);
      nfa.setStartState(strt);
      State end (token);
      strt.setTransion(c,end);
      end.setEndState(true);
      nfa.setEndState(end);


}
