#include <iostream>
#include "include/Token.h"
#include "include/State.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

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


    State s1(t);
    State s2(t2);

    s1.setTransion('a', s2);
    s2.getToken().setName("aa");


    set<State>::iterator it1;

    set<State> ss = s1.getTransion('a');
    for (it1 = ss.begin(); it1 != ss.end(); ++it1) {
        State kk = *it1;
        cout << kk.getToken().getName() << endl;
    }


    return 0;
}
