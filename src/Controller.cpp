//
// Created by zeny on 3/24/20.
//



#include "../include/Controller.h"
#include "../include/Token.h"
#include "../include/DFA.h"
#include <fstream>
#include <sstream>
#include <string>




Controller::Controller() {}


Controller::~Controller() {}

shared_ptr<Token> Controller::preProcess(vector<shared_ptr<Token>> tokens, int tokenNum) {
    return shared_ptr<Token>();
}




set<shared_ptr<Token>> Controller::readToken(string path)
{

    std::ifstream infile(path);

    std::string line;
    int counter = 0 ;
    set <string> allname ;
    set < shared_ptr<Token> > allToken ;
    while (std::getline(infile, line))
    {
     //   cout << counter << endl ;
        counter ++ ;
        /**     std::istringstream iss(line);
                string s ;
        */
        if (line[0] == '[' && line[line.size() -1 ] == ']')
        {

            string newline = line.substr(1, line.size() - 2  ) ;
            std::istringstream iss(newline);
            string s ;
            while (iss >> s)
            {
                shared_ptr<Token> t (new Token()) ;
                string name = "panc_[" + s + "]" ;
                t->setName(name) ;
                t->setPriority(counter);
                t->setPattern(s);
                if (allname.find(name) == allname.end()){
                    allname.insert(name);
                    allToken.insert(t);
                }
            }


        }
        else if (line[0] == '{' && line[line.size() -1 ] == '}')
        {

            string newline = line.substr(1, line.size() - 2  ) ;
            std::istringstream iss(newline);
            string s ;
            while (iss >> s)
            {
                shared_ptr<Token> t (new Token()) ;
                t->setName(s) ;
                t->setPriority(counter);
                t->setPattern(s);
               if (allname.find(s) == allname.end()){
                    allname.insert(s);
                    allToken.insert(t);
                }
            }


        }
        else if (line[0] != '{' && line[0] != ']')
        {
           // cout << line << endl ;
            int index = 0 ;
            for (int i = 0 ; i <  line.size() ; i++)
            {
                if (line[i] == '=' || line[i] == ':')
                {
                    index = i ;
                    break;
                }
            }

            if (index == 0 )
            {
                cout << "eeeeeNow" << endl ;
            }
            string sname = line.substr(0 , index) ;
            shared_ptr<Token> t (new Token()) ;
            t->setName(sname) ;
            string s = line.substr(index+1 , line.size() - index+1) ;
            t->setPriority(counter);
            t->setPattern(s);
            if (allname.find(sname) == allname.end()){
                    allname.insert(sname);
                    allToken.insert(t);
            }



        }
        else
        {
            cout << "error" << endl  ;
            break ;
        }


        // process pair (a,b)
    }

    return allToken;
}
/*
DFA Controller::nfaToDfa(NFA A) {
    list<shared_ptr<State>> states = A.getStates();
    unordered_map<set<shared_ptr<State>>, bool> DStates;
    unordered_map<set<shared_ptr<State>>, bool> DTran;
    set<shared_ptr<State>> s0 = epsClosure(A.getStartState(), '0');
    DStates.insert({s0, false});
    shared_ptr<State> t = getUnMarked(DStates);
    while (t->getToken()->getName() != "") {
        for (auto i = t->getTrans().begin(); i != t->getTrans().end(); ++i) {
            char input = i->first;
            set<shared_ptr<State>> u = epsClosure(epsClosure(t, input), '0');
            if (!checkD(u)) {
                DStates.insert({u, false});
            }
        }
        State t = getUnMarked(DStates);
    }
    return DFA();
}

DFA Controller::minDfa(DFA A) {
    return DFA();
}

NFA Controller::oringAll(vector<NFA> A) {
    NFA *nfa;
    shared_ptr<State> newStartState;
    vector<NFA>::iterator it;
    for (it = A.begin(); it != A.end(); it++) {
        newStartState->setTransion('\0', it->getStartState());
        it->setStartState(newStartState);
    }
    return *nfa;
}

set<shared_ptr<State>> Controller::epsClosure(shared_ptr<State> s, char input) {
    return s->getTransion(input);
}

set<shared_ptr<State>> Controller::epsClosure(set<shared_ptr<State>> s, char input) {
    set<shared_ptr<State>> res;
    for (auto it = s.begin(); it != s.end(); ++it) {
        set<shared_ptr<State>> temp = epsClosure(*it, input);
        res.insert(temp.begin(), temp.end());
    }
    return s;
}

shared_ptr<State> Controller::getUnMarked(unordered_map<set<shared_ptr<State>>, bool> &DStates) {
//    auto iterator = DStates.begin();
//    while (iterator != DStates.end()) {
//        if(!iterator->second)
//            return iterator->first;
//    }
//    return static_cast<shared_ptr<State>>(static_cast<shared_ptr<Token>>(nullptr));
}

bool Controller::checkD(set<shared_ptr<State>> set) {
    return false;
}

*/
