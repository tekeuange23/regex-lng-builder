#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

#include <iostream>
#include <string>
#include "Op.h"

class Pile{ //PILE D'OPERATEURS

public:
    /*************************************CONSTRUCTORS & DESTRUCTOS********************************************/
    Pile();
    ~Pile();
    /***************************************    GETTERS & SETTERS     ********************************************/
    Op   getSommet();
    /*************************************           FUNCTIONS        ********************************************/
    bool pileVide();
    int  nbreElement();
    void empiler(Op const&op);
    void depiler();
    Op depiler2();

private:
    /*************************************Variables Membres*******************************************************/
    std::vector<Op> m_ol;
 };

#endif // PILE_H_INCLUDED
