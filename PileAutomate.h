#ifndef PILEAUTOMATE_H
#define PILEAUTOMATE_H



#include "Automate.h"
#include "Op.h"

class PileAutomat{

public:
    /*************************************CONSTRUCTORS & DESTRUCTOS********************************************/
    PileAutomat();
    ~PileAutomat();
    /***************************************    GETTERS & SETTERS     ********************************************/
    Automate   getSommet();
    /*************************************           FUNCTIONS        ********************************************/
    bool pileVide();
    int  nbreElement();
    void empiler(Automate const&a);
    void depiler();
    Automate* depiler2();
private:
    /*************************************Variables Membres*******************************************************/
    std::vector<Automate> m_al;   //automate list
};



#endif // PILEAUTOMATE_H
