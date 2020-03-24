#include <iostream>
#include "include/Token.h"
#include "include/State.h"
#include <memory>

using namespace std;

int main() {
    cout << "Hello world!" << endl;



    shared_ptr<Token> tt (new Token("ahemd") ) ;
    cout << tt->getName() << endl ;
    tt->setName("ss") ;

     cout << tt->getName() << endl  ;

    Token t;
    //cout << t.getName() << endl;
    t.setName("ahmed");
    t.setPattern("a-z");
    t.setPriority(5);
    //cout << t.getName() ;

    Token t2;
    t2.setName("aaaaaaaa");
    t2.setPattern("a-z");
    t2.setPriority(5);


    State s1(tt);
    State s2(tt);

    s1.setTransion('a', s2);
    //s2.getToken()->setName("aa");
    tt->setName("aa") ;

    set<State>::iterator it1;

    set<State> ss = s1.getTransion('a');
    for (it1 = ss.begin(); it1 != ss.end(); ++it1) {
        State kk = *it1;
        cout << kk.getToken()->getName() << endl;
    }


    return 0;
}
