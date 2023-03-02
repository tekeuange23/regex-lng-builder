#include "State.h"
using namespace std;

//initialisation de la variable de classe;
int State::compter = 0;


/*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/

State::State() : m_name(0), m_isFinal(false){
    this->m_name = (State::compter++);
}
State::State(bool isFinal) : m_name(0), m_isFinal(isFinal){
    this->m_name = (State::compter++);
}
State::State(bool isFinal, std::vector<Arc> al) : m_name(0), m_isFinal(isFinal){
    this->m_name = (State::compter++);
    this->m_arcsList.resize(al.size());
    for(size_t i=0; i<al.size(); i++)
        this->m_arcsList[i] = al[i];
}
State::~State(){
    m_arcsList.clear();
    //State::compter --;
}


/***************************************    GETTERS & SETTERS   **********************************************/
int State::getName()const{
    return this->m_name;
}
bool State::getIsFinal()const{
    return this->m_isFinal;
}
std::vector<Arc> State::getArcList()const{
    return this->m_arcsList;
}
int State::getSize()const{
    return this->m_arcsList.size();
}
int State::getCompter(){
    return State::compter;
}
/*************************************           FONCTIONS       *********************************************/
////////////////////////////ajouts
void State::add_arc(Arc &a){
    this->m_arcsList.push_back(a);
}
void State::add_arc(char symbol, int destination){
    Arc *a =  new Arc(symbol,destination);
    this->add_arc(*a);
}
void State::remove_arc(Arc &a){
    remove_arc(a.getDestination(), a.getSymbol());
}
void State::remove_arc(int destination, char symbol){
    try{
        std::vector<Arc>::iterator     pos    =   searchAr(*(this->searchArc(destination,symbol)) );
        this->m_arcsList.erase(pos);
        cout<<"\nl'arc a ete supprimer\n";
    }catch(ArcNotFoundException e){    e.print();  }
}
void State::setFinal(){
    this->m_isFinal = true;
}
void State::unsetFinal(){
    this->m_isFinal = false;
}
////////////////////////////recherche
bool State::searchArc(Arc const& a){
    for(int i=0; i<this->getSize(); i++)
        if( this->m_arcsList[i] == a )
            return true;
    return false;
}
std::vector<Arc>::iterator State::searchAr(Arc const& a){
    for(std::vector<Arc>::iterator ptr = m_arcsList.begin();  ptr<m_arcsList.end(); ptr++)
        if(*ptr == a)
            return ptr;

    ArcNotFoundException* error = new ArcNotFoundException(298,"You are trying to use an Arc which is not exist.");
    throw *error;
}
Arc* State::searchArc(int destination, char symbol){
    for(int i=0; i<this->getSize(); i++)
        if( this->m_arcsList[i].getDestination() == destination  &&   this->m_arcsList[i].getSymbol() == symbol )
            return &this->m_arcsList[i];
    ArcNotFoundException* error = new ArcNotFoundException(298,"You are trying to use an Arc which is not exist.");
    throw *error;
    return 0;
}
////////////////////////////affichage
void State::showState()const{
    cout<<"\t\t************** STATE Q"<< this->m_name << " **************|" <<endl;
    cout<<"\t\t|\tIsFinal: "   << (m_isFinal ? "true" : "false")<<""<<endl;
    cout<<"\t\t|\tArcList: <--";
    for(int i=0; i<getSize(); i++)
        cout<<"|"<< m_arcsList[i].getSymbol() <<",q"<< m_arcsList[i].getDestination() <<"|"<<(i!=getSize()-1 ? "-" : "");
    cout<<"";
    cout<<"\n\t\t-----------------"<< (this->m_name > 9 ? "-" : "") <<"---------------------|" <<endl<<endl;
}


////////////////////////////Transitions
bool State::searchArc(char symbol){
    for(int i=0; i<this->getSize(); i++)
        if( this->m_arcsList[i].getSymbol() == symbol )
            return true;
    return false;
}

std::vector<int> State::transite(char symbol){
    vector<int> tab;
    for(int i=0; i<this->getSize(); i++)
        if( this->m_arcsList[i].getSymbol() == symbol )
            tab.push_back(this->m_arcsList[i].getDestination());
    return tab;
}



//*************************************           OPERATORS       ***********************************************/
bool operator==(State const& st1, State const& st2){
    bool test = false;
    if (st1.getName() == st2.getName()    &&   st1.getIsFinal() == st2.getIsFinal()   &&    st1.getSize() == st2.getSize()){
        test = true;
        for(int i=0; i<st1.getSize(); i++)
            test = test && (st1.getArcList()[i].getSymbol()==st2.getArcList()[i].getSymbol() && st1.getArcList()[i].getDestination()==st2.getArcList()[i].getDestination());
    }
    return test;
}


