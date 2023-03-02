#ifndef ARC_H
#define ARC_H


#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

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





#endif // ARC_H
