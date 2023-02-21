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

    m_statesList.clear();
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
    try{
        this->m_initialState = searchState(name);
    }catch(StateNotFoundException e){   e.print();    }
}
void Automate::setInitial(State &state){
    this->m_initialState = &state;
}

/*************************************           FONCTIONS       *********************************************/
/////////////////////////////////////////ajouts & suppression
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
void Automate::add_arc(int from, int to, char symbol){
    try{
        searchState(to);    //on verifi si l'etat de destination existe bel et bien
        Arc* a = new Arc(symbol,to);
        this->add_arc(from,*a);
    }
    catch(StateNotFoundException e){    e.print();   }


}
void Automate::remove_state(int name){

    try{
        std::vector<State>::iterator     pos    =   searchStat(*(this->searchState(name)) );
        pos->getArcList().clear();  //on suprime tous les arcs de l'etat en question;
        this->m_statesList.erase(pos);
        cout<<"\nl'etat a ete supprimer\n";
    }catch(StateNotFoundException e){    e.print();  }
}
void Automate::remove_state(State &st){
    for(int i=0; i<st.getSize(); i++)
        st.remove_arc(st.getArcList()[i]);

    delete &st;
}
void Automate::remove_arc(int from, int to, char symbol){
    try{
        State* st = this->searchState(from);
        st->remove_arc(to,symbol);
    }catch(StateNotFoundException e){   e.print();  }

}
void Automate::remove_arc(State &st, Arc &a){
    st.remove_arc(a);
}
void Automate::setFinal(State &st){
    if(this->searchState(st))   //si l'etat pris en parametre est un etat de l'automate en question
        st.setFinal();
}
void Automate::unsetSetFinal(){
    State* st = this->searchFinal();
    st->unsetFinal();
}
/////////////////////////////////////////recherches
bool Automate::searchState(State const &st){
    for(int i=0; i<this->getSize(); i++)
        if(this->m_statesList[i] == st)
           return true;
    return false;
}
std::vector<State>::iterator Automate::searchStat(State const& st){
    for(std::vector<State>::iterator ptr = m_statesList.begin();  ptr<m_statesList.end(); ptr++)
        if(*ptr == st)
            return ptr;

    StateNotFoundException* error = new StateNotFoundException(399,"You are trying to use a State which is not exist.");
    throw *error;               //l'etat n'ayant pas ete trouve, ceci peut generer une exeption: ON LA LEVE;
}
State* Automate::searchState(int name){
    for(int i=0; i<this->getSize(); i++)
        if(this->m_statesList[i].getName() == name)
           return &(this->m_statesList[i]);

    StateNotFoundException* error = new StateNotFoundException(399,"You are trying to use a State which is not exist.");
    throw *error;               //l'etat n'ayant pas ete trouve, ceci peut generer une exeption: ON LA LEVE;
    return 0;
}
State* Automate::searchFinal(){
    for(int i=0; i<this->getSize(); i++)
        if(this->m_statesList[i].getIsFinal())
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
std::vector<Arc>::iterator Automate::searchAr(int from, Arc const& a){
    try{
        State* st = this->searchState(from);
        return st->searchAr(a);
    }catch(ArcNotFoundException e) {    e.print();  }
}
Arc* Automate::searchArc(int from, int to, char symbol){
    try{
        State* s = this->searchState(from);
        s->searchArc(to,symbol);
    }catch(ArcNotFoundException e) {    e.print();  }
}
/////////////////////////////////////////affichage
void Automate::showAutomate()const{
    cout<<"////////////////////////////////  AUTOMATE  /////////////////////////////////"<<endl<<endl;
    cout<<"\t\t\tInitial State : Q"<<this->m_initialState->getName()<<endl<<endl;
    for(int i=0; i<getSize(); i++)
        m_statesList[i].showState();
    cout<<"/////////////////////////////////////////////////////////////////////////////"<<endl;
}




/////////////////////////////////////////CONSTRUCTIONS DE THOMPSON :::::::::: AUTOMATE ASSOCIE A UNE EXPRESSION REGULIERE
Automate* Automate::thompson(char symbol){

    Automate* a = new Automate();
    State* i = new State();
    State* f = new State(true);
    a->m_initialState = i;
    a->add_state(*i);
    a->add_state(*f);
    a->add_arc(i->getName(),f->getName(),symbol);

    return a;
}
Automate* Automate::thompson_or(Automate &a1, Automate &a2){

    Automate* a = new Automate();
    State* i = new State();     //new initial STATE
    i->add_arc('e',a1.getInicialState()->getName());
    i->add_arc('e',a2.getInicialState()->getName());

    State* f = new State(true);
    a1.searchFinal()->add_arc('e',f->getName());
    a1.searchFinal()->unsetFinal();
    a2.searchFinal()->add_arc('e',f->getName());
    a2.searchFinal()->unsetFinal();

    a->m_initialState = i;

    a->add_state(*i);
    for(int i=0; i<a1.getSize(); i++)
        a->add_state(a1.getStatesListe()[i]);
    a->add_state(*f);
    for(int i=0; i<a2.getSize(); i++)
        a->add_state(a2.getStatesListe()[i]);

    return a;
}
//Automate* Automate::thompson_concat(Automate &a1, Automate &a2){}
//Automate* Automate::thompson_star(Automate &a){}




