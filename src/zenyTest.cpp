////
//// Created by zeny on 3/26/20.
////
//#include <iostream>
//#include "../include/Token.h"
//#include "../include/State.h"
//#include "../include/DFA.h"
//#include "../include/Controller.h"
//#include <memory>
//
//using namespace std;
//
//int main() {
//    cout << "Hello world!" << endl;
//    string tokenName1="abcde";
//    Token dummyToken1(tokenName1,"abcde",5);
//    shared_ptr<Token>t1(make_shared<Token>(dummyToken1));
//    vector<State> states(5);
//    for(int i=0;i<states.size()-1;i++){
//        State dummyState (t1);
//        states[i]=(dummyState);
//
//    }
//    State endState (t1);
//    endState.setEndState(true);
//    states[4]=(endState);
//
//    string tokenName2="abcxe";
//    Token dummyToken2(tokenName1,"abcxe",2);
//    shared_ptr<Token>t2(make_shared<Token>(dummyToken2));
//
//    State s2(t2),s1(t2);
//    s2.setEndState(true);
//    s1.setTransion('e',make_shared<State>(s2));
//    states[2].setTransion('x',make_shared<State>(s1));
//
//    for(int i=states.size()-2;i>=0;i--){
//        states[i].setTransion((char)i+'b',make_shared<State>(states[i+1]));
//    }
//
//
//    states.push_back(s1);
//    states.push_back(s2);
//
//    DFA d;
//
//    d.setEndState(states[states.size()-1]);
//    d.setStartState(states[0]);
//    list<State> statesList(states.begin(),states.end());
//    d.setStates(statesList);
//    Controller controller;
//    controller.setD(d);
//    controller.getAllInputs(d);
//
//    int counter=0;
//
//    for(auto i:controller.getD().getStates())
//        counter++;
//
//    cout<<counter<<endl;
//
//    controller.minDfa();
//    counter=0;
//
//    for(auto i:controller.getD().getStates())
//        counter++;
//
//    cout<<counter<<endl;
//    return 0;
//};