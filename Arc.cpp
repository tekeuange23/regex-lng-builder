#include "Arc.h"
using namespace std;

/*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
Arc::Arc() : m_symbol('e'), m_destination(0){}
Arc::Arc(char symbol, int destination) : m_symbol(symbol), m_destination(destination){}
Arc::~Arc(){}
/***************************************    GETTERS & SETTERS   **********************************************/
char Arc::getSymbol()const{
    return m_symbol;
}
int Arc::getDestination()const{
    return m_destination;
}
/*************************************           FONCTIONS       *********************************************/





//*************************************           OPERATEURS       *******************************************/
bool operator==(Arc const& a1, Arc const& a2){
    if(a1.getSymbol() == a2.getSymbol()    &&    a1.getDestination() == a2.getDestination())
        return true;
    else
        return false;
}
