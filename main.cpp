#include <iostream>
#include "include/Token.h"
#include "include/State.h"
#include "include/NFA.h"
#include "include/Controller.h"
#include <memory>


using namespace std;

set<shared_ptr<State>> done;
set<char> allinputs;

Controller c;

void Dfs(shared_ptr<State> s) {
    unordered_map<char, set<shared_ptr<State>>> umap = s->getAllT();
    unordered_map<char, set<shared_ptr<State>>>::iterator itr;
    for (itr = umap.begin(); itr != umap.end(); itr++) {
        if (allinputs.find(itr->first) == allinputs.end()) {
            allinputs.insert(itr->first);
            c.setInput(itr->first);
        }
        set<shared_ptr<State>> ss = itr->second;
        set<shared_ptr<State>>::iterator it1;
        for (it1 = ss.begin(); it1 != ss.end(); ++it1) {
            shared_ptr<State> kk = *it1;
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
    shared_ptr<Token> token(new Token("or"));
    token->setPattern("a-z");
    token->setPriority(INT_MAX);
    NFA b(0, token);
    set<shared_ptr<Token>> all = c.readToken("input.txt");
    set<shared_ptr<Token>>::iterator itr;
    for (itr = all.begin(); itr != all.end(); ++itr) {
        shared_ptr<Token> kk = *itr;
    }

    NFA a = b.parcingPattern(all);
    done.insert(a.getStartState());

    done.insert(a.getStartState());
    Dfs(a.getStartState());
    DFA d = c.nfaToDfa(a);
    done.clear();
    done.insert(d.getStartState());
    Dfs(d.getStartState());
    c.minDfa();
    cout << endl << endl << endl << endl;
    int x = 1;
    printf("state ##:  ");
    for (int i = 1; i < c.getInputs().size(); ++i) {
        printf("%10c", c.getInputs()[i]);
    }
    cout << endl;
    for (auto state : d.getStates()) {
        printf("state %2d:  %10s", x++, state->getToken()->getName().c_str());
        for (int i = 1; i < c.getInputs().size(); ++i) {
            if (state->getTransion(c.getInputs()[i]).size() > 0)
                printf("%10s", state->getTransion(
                        c.getInputs()[i]).begin()->operator->()->getToken()->getName().c_str());
            else
                printf("|--------|");
        }
        cout << endl;
    }

    done.clear();
    done.insert(d.getStartState());
    Dfs(d.getStartState());
    cout << "num of states " << done.size() << endl;
    c.readInput("codeInput.txt", d);

    return 0;
}
