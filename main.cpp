#include <iostream>
#include "include/Token.h"
#include "include/State.h"
#include <memory>
#include <Controller.h>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Controller controller;
    NFA nfa;
    DFA dfa;

    shared_ptr<State> one(new State(shared_ptr<Token>(new Token("1")))),
            two(new State(shared_ptr<Token>(new Token("2")))),
            three(new State(shared_ptr<Token>(new Token("3")))),
            four(new State(shared_ptr<Token>(new Token("4"))));
    list<shared_ptr<State>> list;
    list.push_back(one);
    list.push_back(two);
    list.push_back(three);
    list.push_back(four);

    one->setTransion('a', two);
    one->setTransion('c', four);
    one->setTransion('0', one);

    two->setTransion('b', three);
    two->setTransion('0', one);
    two->setTransion('0', two);

    three->setTransion('a', two);
    three->setTransion('0', three);

    four->setTransion('c', three);
    four->setTransion('0', four);
    four->setTransion('0', three);

    nfa.setStartState(one);
    nfa.setStates(list);
    nfa.setEndState(three);

    controller.setInput('a');
    controller.setInput('b');
    controller.setInput('c');
//    controller.setInput('0');

    dfa = controller.nfaToDfa(nfa);
    cout << "finito" << endl;

    return 0;
}
