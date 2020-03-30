//
// Created by zeny on 3/24/20.
//

#ifndef COMPILER_CONTROLLER_H
#define COMPILER_CONTROLLER_H

#include "NFA.h"
#include "Token.h"
#include "DFA.h"

class Controller {
private:
    vector<shared_ptr<Token>> tokens;
    vector<NFA> A;
    NFA N;
    DFA D;
    vector<char >inputs;

  //  set<struct shared_ptr<State>> epsClosure(shared_ptr<State> s, char input);

  //  set<shared_ptr<State>> epsClosure(set<shared_ptr<State>> s, char input);

  //  shared_ptr<State> getUnMarked(unordered_map<set<shared_ptr<State>>, bool> &DStates);

    bool equalStates(vector<vector<State>> p, State s1, State s2);

    vector<vector<State>> smash(vector<vector<State>> p);

    vector<vector<State>> split(vector<State> s);

    bool areEqual(vector<vector<State>> p, State s1, State s2, char in);

    bool inSameVector(vector<vector<State>> p, shared_ptr<State> t1, shared_ptr<State> t2);

    bool statesExistInVector(vector<State> p, shared_ptr<State> t1, shared_ptr<State> t2);

    bool containSamePartitions(vector<vector<State>> v1, vector<vector<State>> v2);

    void reflectMinimizedDfa(const vector<vector<State>>& partitions);

    void mushTwoStates(vector<State>s, State state, State state1);

public:
  //  Controller();

 //   virtual ~Controller();
    const vector<shared_ptr<Token>> &getTokens() const;

    void setTokens(const vector<shared_ptr<Token>> &tokens);

    const vector<NFA> &getA() const;

    void setA(const vector<NFA> &a);

    const NFA &getN() const;

    void setN(const NFA &n);

    const DFA &getD() const;

    void setD(const DFA &d);

    shared_ptr<Token> readToken(string path);

    shared_ptr<Token> preProcess(vector<shared_ptr<Token>> tokens, int tokenNum);

    NFA oringAll(vector<NFA> A);

    void minDfa();

 //   DFA nfaToDfa(NFA A);

    void getAllInputs(DFA A);


 //   bool checkD(set<shared_ptr<State>> set);

};


#endif //COMPILER_CONTROLLER_H
