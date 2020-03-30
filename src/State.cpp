#include "../include/State.h"
#include "../include/Token.h"
#include <memory>

State::State() {
    //ctor
}

State::~State() {
    //dtor
}

State::State(shared_ptr<Token> stateToken) : stateToken(stateToken) {
    //cout << State::stateToken->getName() << "gg\n";
    endState = false;
}


bool State::isEndState() {
    return endState;
}

 unordered_map<char, set<shared_ptr<State>>> State::getAllT() {

    return trans ;
 }

void State::setTransion(char input, shared_ptr<State> e) {
    if (trans[input].find(e) == trans[input].end()) {
        trans[input].insert(e);
    } else {
        cout << "error" << endl;
    }
}


set<shared_ptr<State>> State::getTransion(char input) {

    if (trans.find(input) == trans.end()) {
        set<shared_ptr<State>> s;
        return s;
    }

    return trans[input];
}

void State::setEndState(bool end) {
    endState = end;
}

void State::setToken(shared_ptr<Token> t) {
    stateToken = t;
}

shared_ptr<Token> State::getToken() {

    return stateToken;
}


bool operator<(const State &left, const State &right) {
    State l = left;
    State r = right;

    return l.getToken()->getName() < r.getToken()->getName();
}

bool State::same(State s) {
    bool st=this->getTrans()==s.getTrans();
    bool ses=this->isEndState()==s.isEndState();
    return  st&&ses;
}

/*
bool operator< (const State &left, const State &right)
{

    return reinterpret_cast<const char*>( std::addressof(left) ) < reinterpret_cast<const char*>( std::addressof(right) ) ;
}

bool operator== (const State &left, const State &right)
{

    return reinterpret_cast<const char*>( std::addressof(left) ) == reinterpret_cast<const char*>( std::addressof(right) );
}
*/

unordered_map<char, set<shared_ptr<State>>> State::getTrans() {
    return trans;
}
 void State:: clone(shared_ptr<State> oldS,shared_ptr<State> newS,unordered_map<shared_ptr<State>, shared_ptr<State>> &mapS)
 {
    // cout << "yesss" << endl;
     unordered_map<char, set<shared_ptr<State>>> umap = oldS->getAllT() ;


     if(umap.empty())
     {


         if(mapS.find(oldS)!=mapS.end())
         {
            mapS[oldS]=newS;
         }

     }

     unordered_map<char, set<shared_ptr<State>>> :: iterator itr;

     for(itr = umap.begin(); itr != umap.end(); itr++)
     {

          char c=itr->first;
          // cout << c << endl;
          set<shared_ptr<State>> setS;
          setS=itr->second;

          set<shared_ptr<State>>::iterator itS;
          for(itS = setS.begin(); itS != setS.end(); itS++)
          {
             shared_ptr<State> oS =*itS;

             if(mapS.find(oS)==mapS.end())
             {

                 shared_ptr<State> nS(new State(oS->getToken()));
                 clone(oS,nS,mapS);
                 mapS[oS]=nS;
                 newS->setTransion(c,nS);

             }
             else
             {
                 newS->setTransion(c,mapS[oS]);

             }
          }
     }
     //  cout << "Sdfaaaaaaaaaaaa" << endl;

     newS->setToken(oldS->getToken());
     newS->setEndState(oldS->isEndState());


 }
/*bool operator< ( State &left,  State &right)
{
    return left.getToken().getName() < right.getToken().getName();
}*/
/*bool operator< (const Point2D &right) const
{
    return etToken().getName() < right.getToken().getName();
}*/
