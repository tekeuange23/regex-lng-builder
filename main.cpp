#include "Automate.h"

using namespace std;


int main()
{
    //////////////////////////////////arcs
    Arc* a1 = new Arc('a',2);
    Arc* a2 = new Arc('a',3);
    Arc* b1 = new Arc('b',4);
    Arc* b2 = new Arc('b',1);
    Arc* b3 = new Arc('b',1);
    Arc* b4 = new Arc('b',1);
    vector<Arc> va1;     va1.push_back(*a1);   va1.push_back(*b3);
    vector<Arc> va2;     va2.push_back(*a2);   va2.push_back(*b4);
    vector<Arc> va3;     va3.push_back(*b1);
    vector<Arc> va3;     va3.push_back(*b2);
    //////////////////////////////////states
    State* st1 = new State(true, va1);
    State* st2 = new State(true, va2);
    State* st3 = new State(false,  va3);
    State* st4 = new State(false,  va3);
    vector<State> vs;   vs.push_back(*st1);   vs.push_back(*st2);   vs.push_back(*st3);
    //////////////////////////////////automate
    Automate* aut = new Automate(st1, vs);
    cout<<"\n\n\n";



    if(*st1 == *st1  && *a1 == *a2)
        (*aut).showAutomate();
    cout<<"\n\n\n";
    aut->setInitial(*st3);
    aut->add_state();
    aut->add_arc(3,*new Arc('a',2));
    aut->add_arc(4,'a',2);
    aut->showAutomate();
    try{    State* s = aut->searchState(4);    }catch(StateNotFoundException e){    e.print();   }

    cout<<"\n---------------------------nnn\n";
    st3->showState();
    st3->showState();



    return 0;
}