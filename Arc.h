#ifndef ARC_H_INCLUDED
#define ARC_H_INCLUDED

#include <iostream>
#include <string>
#include <iterator>
#include <vector>

//#include "State.h"

class Arc{

public:
    /*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
    Arc();
    Arc(char symbol, int destination);
    ~Arc();
    /***************************************    GETTERS & SETTERS   **********************************************/
    char getSymbol()const;
    int getDestination()const;
    /*************************************           FONCTIONS       *********************************************/

private:
    /*************************************Variables Membres*******************************************************/
    char    m_symbol;       //lettre de l'alphabet;
    int     m_destination;  //nom de l'etat de destination;
};





//*************************************           OPERATORS       ***********************************************/
bool operator==(Arc const&, Arc const&);





#endif // ARC_H_INCLUDED
