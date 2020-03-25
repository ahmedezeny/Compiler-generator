#include <iostream>
#include "include/Token.h"
#include "include/State.h"
#include <memory>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    //shared_ptr<State>


    Token tf ;
    tf.setName("ahemd") ;

   // shared_ptr<Token> tt = make_shared<Token>(tf);
    shared_ptr<Token> tt ( make_shared<Token>(tf) );
    State s(tt) ;
    State ss = s ;
    cout << s.getToken()->getName() << endl ;
    cout << ss.getToken()->getName() << endl ;
    s.getToken()->setName("asf") ;
    cout << s.getToken()->getName() << endl ;
    cout << ss.getToken()->getName() << endl ;
  //  cout << tt->getName() << endl ;
    tt->setName("ss") ;

    cout << s.getToken()->getName() << endl ;
    cout << ss.getToken()->getName() << endl ;
   // cout << tt->getName() << endl  ;


    //Token *t2 = tf ;

   // Token *t3 = tt.get() ;
/*
    shared_ptr<State> s1(new State(tt));
    shared_ptr<State> s2(new State(tt));

    s1->setTransion('a', s2);
    s1->setTransion('a', s2);
    s1->setTransion('a', s2);
    s2->getToken()->setName("aa");
    tt->setName("aa") ;

    //cout << tf.getName() << endl ;
    //cout << t2->getName() << endl;

    set<shared_ptr<State>>::iterator it1;

    set<shared_ptr<State>> ss = s1->getTransion('a');

    for (it1 = ss.begin(); it1 != ss.end(); ++it1) {
        shared_ptr<State> kk = *it1;
        cout << kk->getToken()->getName() << endl;
    }

*/

    return 0;
}
