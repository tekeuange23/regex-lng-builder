#include "Regex.h"

using namespace std;


int main()
{
/*
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
    vector<Arc> va4;     va4.push_back(*b2);
    //////////////////////////////////states
    State* st1 = new State(true, va1);
    State* st2 = new State(true, va2);
    State* st3 = new State(false,  va3);
    State* st4 = new State(false,  va4);
    vector<State> vs;   vs.push_back(*st1);   vs.push_back(*st2);   vs.push_back(*st3);     vs.push_back(*st4);
    //////////////////////////////////automate
    Automate* aut = new Automate(st1, vs);
    cout<<"\n\n\n";

    aut->showAutomate();
        aut->remove_arc(2,1,'b');
        aut->remove_arc(2,3,'a');
        aut->remove_arc(1,1,'b');
        aut->remove_arc(2,3,'b');
        aut->remove_state(4);
        aut->remove_state(4);
    aut->showAutomate();

    //
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
*/

/*

    Automate* a1;
    a1 = a1->thompson('a');
    //a1->showAutomate();

    Automate* a2;
    a2 = a2->thompson('b');
    //a2->showAutomate();

    Automate* a3;
    a3 = a3->thompson('c');
    //a3->showAutomate();

    Automate* a;
    a = ~*a1;
    a->showAutomate();


    //Automate* A = A->thompson_concat(*a, *a3);
    //A->showAutomate();

    //Automate* AA = AA->thompson_star(*A);
    //AA->showAutomate();
*/

/*
    vector<Regex> rel;
    rel.push_back(*(new Regex("(a/b)*abb")));
    rel.push_back(*(new Regex("a(ab+a)*b")));
    rel.push_back(*(new Regex("(a/b)*(a/b)")));
    rel.push_back(*(new Regex("(a+b)*a(a/b)(a/b)")));
    rel.push_back(*(new Regex("a*b*(c*+d*)")));
    rel.push_back(*(new Regex("a*bc*")));
    rel.push_back(*(new Regex("(a* / b*)*")));
    rel.push_back(*(new Regex("b*ab*ab*ab*")));

    rel.push_back(*(new Regex("a*cv*..s")));

    rel.push_back(*(new Regex("(a/b)*")));
    rel.push_back(*(new Regex("(a/b)*(a/b)")));
    rel.push_back(*(new Regex("(a/b)(a/b)")));
    rel.push_back(*(new Regex("abc")));
    for(int i=0; i<rel.size(); i++){
        rel[i].showString();
        rel[i].showInfixe();
        rel[i].showPosfixe();
    }

*/

     Regex* r = new Regex("(a/b)*abb");
     //Regex* r = new Regex("a/b");
     r->showPosfixe();
     //r->showInfixe();
     Automate aut = r->evaluation();
     aut.showAutomate();

    return 0;
}
