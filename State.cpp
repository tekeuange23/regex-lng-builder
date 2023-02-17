#include "State.h"
using namespace std;

//initialisation de la variable de classe;
int State::compteur = 0;


/*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/

State::State() : m_name(0), m_isFinal(false), m_arcsList(0){
    m_name = (++ State::compteur);
}
State::State(bool isFinal, std::vector<Arc> al) : m_name(0), m_isFinal(isFinal), m_arcsList(0){
    this->m_name = (++ State::compteur);
    this->m_arcsList.resize(al.size());
    for(size_t i=0; i<al.size(); i++)
        this->m_arcsList[i] = al[i];
}
State::~State(){
    for(int i=0; i<this->getSize(); i++)
        delete &m_arcsList[i];
    //State::compteur --;
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
void State::setFinal(){
    this->m_isFinal = true;
}

/*************************************           FONCTIONS       *********************************************/

void State::add_arc(Arc &a){
    this->m_arcsList.push_back(a);
    this->showState();
    //int n = this->getSize()+1;
    //this->m_arcsList.resize(n);
    //this->m_arcsList[n-1] = a;
}
void State::add_arc(char symbol, int destination){
    Arc *a =  new Arc(symbol,destination);
    this->add_arc(*a);
}
void State::remove_arc(Arc &a){
    delete &a;
}
void State::remove_arc(int destination, char symbol){
    Arc* a = searchArc(destination,symbol);
    delete a;
    a = 0;
}
bool State::searchArc(Arc const& a){
    for(int i=0; i<this->getSize(); i++)
        if( this->m_arcsList[i] == a )
            return true;
    return false;
}
Arc* State::searchArc(int destination, char symbol){
    for(int i=0; i<this->getSize(); i++)
        if( this->m_arcsList[i].getDestination() == destination  &&   this->m_arcsList[i].getSymbol() == symbol )
            return &this->m_arcsList[i];
    ArcNotFoundException* error = new ArcNotFoundException(298,"You are trying to use an Arc which is not exist.");
    throw *error;
    return 0;
}
void State::showState()const{
    cout<<"\t\t*************** STATE "<< m_name << " **************|" <<endl;
    cout<<"\t\t|\tIsFinal: "   << (m_isFinal ? "true" : "false")<<""<<endl;
    cout<<"\t\t|\tArcList: <--";
    for(int i=0; i<getSize(); i++)
        cout<<"|"<< m_arcsList[i].getSymbol() <<","<< m_arcsList[i].getDestination() <<"|"<<(i!=getSize()-1 ? "-" : "");
    cout<<"";
    cout<<"\n\t\t--------------------------------------|" <<endl<<endl;
}




//************************************           OPERATEURS       ********************************************/
bool operator==(State const& st1, State const& st2){
    bool test = false;
    if (st1.getName() == st2.getName()    &&   st1.getIsFinal() == st2.getIsFinal()   &&    st1.getSize() == st2.getSize()){
        test = true;
        for(int i=0; i<st1.getSize(); i++)
            test = test && (st1.getArcList()[i].getSymbol()==st2.getArcList()[i].getSymbol() && st1.getArcList()[i].getDestination()==st2.getArcList()[i].getDestination());
    }
    return test;
}


