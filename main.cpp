#include <bits/stdc++.h>
#include "State.h"
#include "Token.h"
#include "NFA.h"
#include "DFA.h"

using namespace std;

int main() {

    cout << "Hello, World!" << std::endl;
    Token t ; 
    t.setName("ahmed") ; 
    t.setPattern("a-z") ; 
    t.setPriority(5) ; 
    Token t2 ; 
    t.setName("aaaaaaaa") ; 
    t.setPattern("a-z") ; 
    t.setPriority(5) ; 

    State s(t);
    State s2(t2) ;
     
    s.setTransion('a' , s2) ; 

    s2.getToken().setName("aa") ; 
     
    set<State>::iterator it1 ; 

    for (it1 = s.getTransion('a').begin(); it1 != s.getTransion('a').end();  ++it1){ 
         Token kk =  *it1->getToken().getName() ;  
    }
     
    

    return 0;
}
