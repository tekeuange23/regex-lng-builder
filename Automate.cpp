#include "Automate.h"
using namespace std;

/*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
Automate::Automate()    :   m_initialState(0),      m_statesList(0){}
Automate::Automate(State* initialState, std::vector<State> sl)    :   m_initialState(0){

    this->m_initialState = initialState;
    this->m_statesList.resize(sl.size());
    for(size_t i=0; i<sl.size(); i++)
        m_statesList[i] = sl[i];
}
Automate::~Automate(){
    delete m_initialState;
    m_initialState=0;

    for(int i=0; i<this->getSize(); i++)
        delete &(m_statesList[i]);
}

/***************************************    GETTERS & SETTERS   **********************************************/
State* Automate::getInicialState()const{
    return m_initialState;
}
std::vector<State> Automate::getStatesListe()const{
    return m_statesList;
}
int Automate::getSize()const{
    return this->m_statesList.size();
}
void Automate::setInitial(int name){
    this->m_initialState = searchState(name);
}
void Automate::setInitial(State &state){
    this->m_initialState = &state;
}

/*************************************           FONCTIONS       *********************************************/
Automate* Automate::cloner_automate(Automate const &a){

    Automate* a1 = new Automate();
    a1->m_initialState = a.m_initialState;
    a1->m_statesList.resize(a.m_statesList.size());
    for(int i=0; i<a.getSize(); i++)
        a1->m_statesList[i] = a.m_statesList[i];
    return a1;
}
int Automate::add_state(){
    State* st = new State();
    this->m_statesList.push_back(*st);

    return st->getName();
}
void Automate::add_state(State &st){
    this->m_statesList.push_back(st);
}
void Automate::add_arc(int name, Arc &a){
    try{
    //cas ou l'etat cherchee n'est pas trouvee
        State* st = this->searchState(name);
        st->add_arc(a);

    }
    catch(StateNotFoundException e){
        e.print();
    }
}
void Automate::add_arc(int name, char symbol, int destination){
    Arc* a = new Arc(symbol,destination);
    this->add_arc(name,*a);
}
void Automate::remove_state(int name){
    State* st = this->searchState(name);
    for(int i=0; i<st->getSize(); i++)
        st->remove_arc(st->getArcList()[i]);
    delete st;
    st = 0;
}
void Automate::remove_state(State &st){\
    for(int i=0; i<st.getSize(); i++)
        st.remove_arc(st.getArcList()[i]);
    delete &st;
}
void Automate::remove_arc(int from, int to, char symbol){
    State* st = this->searchState(from);
    st->remove_arc(to,symbol);
}
void Automate::remove_arc(State &st, Arc &a){
    st.remove_arc(a);
}

void Automate::showAutomate()const{
    cout<<"////////////////////////////////  AUTOMATE  /////////////////////////////////"<<endl<<endl;
    cout<<"\t\t\tInitial State: STATE "<<this->m_initialState->getName()<<endl<<endl;
    for(int i=0; i<getSize(); i++)
        m_statesList[i].showState();
    cout<<"/////////////////////////////////////////////////////////////////////////////"<<endl;
}
bool Automate::searchState(State const &st){
    for(int i=0; i<this->getSize(); i++)
        if(this->m_statesList[i] == st)
           return true;
    return false;
}
State* Automate::searchState(int name){
    for(int i=0; i<this->getSize(); i++)
        if(this->m_statesList[i].getName() == name)
           return &(this->m_statesList[i]);

    StateNotFoundException* error = new StateNotFoundException(399,"You are trying to use a State which is not exist.");
    throw *error;               //l'etat n'ayant pas ete trouve, ceci peut generer une exeption: ON LA LEVE;
    return 0;
}
bool Automate::searchArc(int from, Arc const& a){
    try{
        State* s = this->searchState(from);
        s->searchArc(a);
    }catch(ArcNotFoundException e) {    e.print();  }
}
Arc* Automate::searchArc(int from, int to, char symbol){
    try{
        State* s = this->searchState(from);
        s->searchArc(to,symbol);
    }catch(ArcNotFoundException e) {    e.print();  }
}
void Automate::setFinal(State &st){
    if(this->searchState(st))   //si l'etat pris en parametre est un etat de l'automate en question
        st.setFinal();
}

