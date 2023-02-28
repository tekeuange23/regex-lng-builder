#include "Pile.h"
using namespace std;

/***************************************CONSTRUCTORS & DESTRUCTOS*********************************************/
Pile::Pile(){}
Pile::~Pile(){}
/***************************************    GETTERS & SETTERS     ********************************************/
Op Pile::getSommet(){
    if(!this->pileVide())
        return this->m_ol[m_ol.size()-1];
}
/*************************************           FUNCTIONS        ********************************************/
bool Pile::pileVide(){
    return this->m_ol.size() == 0;
}
int  Pile::nbreElement(){
    return this->m_ol.size();
}
void Pile::empiler(Op const&op){
    this->m_ol.push_back(op);
}
void Pile::depiler(){
    if(!this->pileVide())
        this->m_ol.pop_back();
}
Op  Pile::depiler2(){

    if(!this->pileVide()){
        Op* op = new Op( m_ol[m_ol.size() - 1] );
        this->m_ol.pop_back();
        return *op;
    }
}
