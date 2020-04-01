//#include <iostream>
//#include "include/Token.h"
//#include "include/State.h"
//#include "include/NFA.h"
//#include "include/Controller.h"
//#include <memory>
//#include <Controller.h>
//
//using namespace std;
//
//set<shared_ptr<State>> done;
//
//void Dfs(shared_ptr<State> s) {
//
//    cout << "new state : " << s->getToken()->getName() << "  "
//         << s->isEndState() << endl;
//    unordered_map<char, set<shared_ptr<State>>> umap = s->getAllT();
//    unordered_map<char, set<shared_ptr<State>>>::iterator itr;
//    // cout << "\nAll Elements : \n";
//    for (itr = umap.begin(); itr != umap.end(); itr++) {
//
//        cout << ">>  input  " << itr->first << endl;
//        set<shared_ptr<State>> ss = itr->second;
//        set<shared_ptr<State>>::iterator it1;
//        for (it1 = ss.begin(); it1 != ss.end(); ++it1) {
//            shared_ptr<State> kk = *it1;
//            cout << kk->getToken()->getName() << " " << kk->isEndState()
//                 << endl;
//        }
//    }
//
//    for (itr = umap.begin(); itr != umap.end(); itr++) {
//
//
//        set<shared_ptr<State>> ss = itr->second;
//        set<shared_ptr<State>>::iterator it1;
//        for (it1 = ss.begin(); it1 != ss.end(); ++it1) {
//            shared_ptr<State> kk = *it1;
//            if (done.find(kk) != done.end()) continue;
//            done.insert(kk);
//            Dfs(kk);
//        }
//
//
//    }
//
//}
//
//
//int main() {
//    cout << "Hello world!" << endl;
//    //shared_ptr<State>
//    shared_ptr<Token> token(new Token("or"));
//    token->setPattern("a-z");
//    token->setPriority(10);
//
//    Controller c;
//
//    set<shared_ptr<Token>> all = c.readToken("input2.txt");
//    set<shared_ptr<Token>>::iterator itr;
//    for (itr = all.begin(); itr != all.end(); ++itr) {
//        shared_ptr<Token> kk = *itr;
//        cout << kk->getName() << " " << kk->getPattern() << endl;
//    }
//
//    NFA b(0, token);
//    NFA a = b.parcingPattern(all);
//    done.insert(a.getStartState());
//    Dfs(a.getStartState());
//    cout << "num of states " << done.size();
//
///*
//   shared_ptr<Token> token (new Token("ahmed"));
////    shared_ptr<Token> tokenor (new Token("or"));
//    token->setPattern("a-z") ;
//    token->setPriority(10) ;
//
//    NFA f (0, token);
//    NFA c=f.charOP("a",token);
//    NFA b=f.plusNFA(c,token);
//    string    s = "a+" ;
//    NFA a = f.parcingOne(s ,  token);
//    done.insert(a.getStartState());
//    Dfs(b.getStartState()) ;
//    cout << "num of states " << done.size() ;
//*/
//    return 0;
//}
