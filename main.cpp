#include <bits/stdc++.h>
#include "State.h"

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
    

    return 0;
}
