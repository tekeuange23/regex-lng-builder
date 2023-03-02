#include "PileAutomate.h"
using namespace std;

/***************************************CONSTRUCTORS & DESTRUCTOS*********************************************/
PileAutomat::PileAutomat(){}
PileAutomat::~PileAutomat(){}


/***************************************    GETTERS & SETTERS     ********************************************/
Automate PileAutomat::getSommet(){
    if(!this->pileVide())
        return this->m_al[m_al.size()-1];
}

/*************************************           FUNCTIONS        ********************************************/
bool PileAutomat::pileVide(){
    return this->m_al.size() == 0;
}
int  PileAutomat::nbreElement(){
    return this->m_al.size();
}
void PileAutomat::empiler(Automate const& a){
    this->m_al.push_back(a);
}
void PileAutomat::depiler(){
    if(!this->pileVide())
        this->m_al.pop_back();
}
Automate* PileAutomat::depiler2(){

    if(!this->pileVide()){
        Automate* a = new Automate( this->getSommet() );
        this->m_al.pop_back();
        return a;
    }

}
