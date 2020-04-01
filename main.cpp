#include <iostream>
#include "include/Token.h"
#include "include/State.h"
#include "include/NFA.h"
#include "include/Controller.h"
#include <memory>


using namespace std;

set<shared_ptr<State>> done;
set<char> allinputs ;

Controller c;

void Dfs(shared_ptr<State> s) {

    // cout << "Sfaaaaaaaaaaaaaaaaaaaa" << endl ;
    if (s->isEndState())
        cout << "new state : " << s->getToken()->getName() << "  "
             << s->isEndState() << endl;
    // cout << "ffffffffffffffffffffffff" << endl ;
    unordered_map<char, set<shared_ptr<State>>> umap = s->getAllT();
    unordered_map<char, set<shared_ptr<State>>>::iterator itr;
    // cout << "\nAll Elements : \n";
    for (itr = umap.begin(); itr != umap.end(); itr++) {
        if (itr->first == 0){
            cout << "null" << endl ;
        }
        if (allinputs.find(itr->first) == allinputs.end()){
            allinputs.insert (itr->first) ;
            c.setInput(itr->first);
        }
        // cout << ">>  input  " << itr->first << endl;
        set<shared_ptr<State>> ss = itr->second;
        set<shared_ptr<State>>::iterator it1;
        for (it1 = ss.begin(); it1 != ss.end(); ++it1) {
            shared_ptr<State> kk = *it1;
            /*  if (kk->isEndState()){
                  cout << kk->getToken()->getName() << " " << kk->isEndState()
                       << endl;
                  }*/
        }
    }

    for (itr = umap.begin(); itr != umap.end(); itr++) {


        set<shared_ptr<State>> ss = itr->second;
        set<shared_ptr<State>>::iterator it1;
        for (it1 = ss.begin(); it1 != ss.end(); ++it1) {
            shared_ptr<State> kk = *it1;
            if (done.find(kk) != done.end()) continue;
            done.insert(kk);
            Dfs(kk);
        }


    }

}


int main() {
    cout << "Hello world!" << endl;
    //shared_ptr<State>
    shared_ptr<Token> token(new Token("or"));
    token->setPattern("a-z");
    token->setPriority(INT_MAX);


    NFA b(0, token);

    set<shared_ptr<Token>> all = c.readToken("input.txt");
    set<shared_ptr<Token>>::iterator itr;
    for (itr = all.begin(); itr != all.end(); ++itr) {
        shared_ptr<Token> kk = *itr;
        cout << kk->getName() << " " << kk->getPattern() << endl;
    }


    NFA a = b.parcingPattern(all);
    done.insert(a.getStartState());

//
    //  NFA a = b.intervalOP('0' , '9' , token) ;

    done.insert(a.getStartState());
    Dfs(a.getStartState());
    cout << "num of states " << done.size() << endl;

    cout << "num of inputs " << allinputs.size() << endl;

    //  for (auto a: allinputs){
    //      cout << (int) a << endl ;
    //  }


    DFA d = c.nfaToDfa(a) ;
    c.minDfa();
    cout << "sssssssssssssssss" << endl ;
    done.clear();
    done.insert(d.getStartState());
    Dfs(d.getStartState());
    cout << "num of states " << done.size();

    return 0;
}
