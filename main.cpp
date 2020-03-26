#include <iostream>
#include "include/Token.h"
#include "include/State.h"
#include "include/NFA.h"
#include <memory>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    //shared_ptr<State>



    shared_ptr<Token> token (new Token("ahmed"));
    shared_ptr<Token> tokenor (new Token("or"));
    token->setPattern("a-z") ;
    token->setPriority(10) ;
    NFA f ;
    string s = token->getPattern() ;
    NFA a =  f.intervalOP('a' , 'z' , token) ;
    NFA b = f.intervalOP('0' , '9' , token) ;


    shared_ptr<State> AstartS , AendState ;
    AendState = a.getEndState() ;
    AstartS = a.getStartState() ;


    shared_ptr<State> BstartS , BendState ;
    BendState = b.getEndState() ;
    BstartS = b.getStartState() ;


     NFA orr = f.oring(a , b , tokenor) ;
    shared_ptr<State> oRstartS , oRendState ;
    oRendState = orr.getEndState() ;
    oRstartS = orr.getStartState() ;

    set<shared_ptr<State>> ss2 = oRstartS->getTransion(0);
    cout << ss2.size()  ;


    set<shared_ptr<State>>::iterator it1;
     it1 = ss2.begin() ;
    if (*it1 == AstartS || *it1 == BstartS) cout << "yes" << endl ;

    cout << BendState->isEndState() ;
    cout << AendState->isEndState() ;
    cout << oRendState->isEndState() ;




/*    set<shared_ptr<State>> ss2 = startS->getTransion('g');
    cout << ss2.size()  ;

    set<shared_ptr<State>>::iterator it1;
    it1 = ss2.begin() ;
    if (*it1 == endState) cout << "yes" << endl ;
    cout << (*it1)->getToken()->getName() ;*/
   // it1 = startS->getTransion('f') ;

    //cout << a.getStartState()->getToken()->getName() ;
   // shared_ptr<State> kk = *it1;



/*
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
*/

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
  /*  shared_ptr<Token> token (new Token("ahmed"));

    Token j = *token ;
    cout << j.getName() ;
    shared_ptr<Token> to = make_shared<Token>(j) ;

    to->setName("Aaaaaaaaaa") ;

    cout << to->getName()  << endl;
    cout << token->getName() << endl;*/

/*
shared_ptr<Token> token (new Token("ahmed"));
     token->setPattern("a-z]") ;
    token->setPriority(10) ;
    NFA f ;
    string s = token->getPattern() ;
    NFA a =  f.intervalOP (s , token) ;*/
/*
    token->setPattern("a-z]") ;
    token->setPriority(10) ;
    NFA f ;
    string s = token->getPattern() ;
    NFA a =  f.intervalOP (s , token) ;
  //  cout << "dfd" ;

    set<shared_ptr<State>>::iterator it1;
    set<shared_ptr<State>> ss = a.getStartState()->getTransion('f');

    for (it1 = ss.begin(); it1 != ss.end(); ++it1) {
        shared_ptr<State> kk = *it1;
        cout << kk->getToken()->getName() << endl;
        kk->getToken()->setName("sdfas") ;
    }


   set<shared_ptr<State>> ss2 = a.getStartState()->getTransion('g');

    if (ss2 == ss){
       cout << "yes" << endl ;
    }

    for (it1 = ss.begin(); it1 != ss.end(); ++it1) {
        shared_ptr<State> kk = *it1;
        cout << kk->getToken()->getName() << endl;
    }
   /* cout << a.getStartState()->getToken()->getName() << endl ;
    cout << a.getStartState()->getToken()->getName() << endl ;
*/
    return 0;
}
