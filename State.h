#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Arc.h"
#include "ArcNotFoundException.h"

class State{

public:
    /*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
    State();
    State(bool isFinal, std::vector<Arc> al);  //consteucteur de copie d'un tableau d'arcs
    ~State();
    /***************************************    GETTERS & SETTERS     ********************************************/
    int getName()const;
    bool getIsFinal()const;
    std::vector<Arc> getArcList()const;
    int getSize()const;
    void setFinal();

    /*************************************           FONCTIONS        ********************************************/
    ////////////////////////////ajouts
    void add_arc(Arc &a);
    void add_arc(char symbol, int destination);
    void remove_arc(Arc &a);
    void remove_arc(int destination, char symbol);
    ////////////////////////////recherche
    bool searchArc(Arc const& a);
    std::vector<Arc>::iterator searchAr(Arc const& a);
    Arc* searchArc(int destination, char symbol);
    ////////////////////////////affichage
    void showState()const;



//variables de classe
    static int compteur;
private:
    /*************************************Variables Membres*******************************************************/
    int                 m_name;     //nom de l'etat ;
    bool                m_isFinal;  //est ce qu'il est un etat d'acceptation? ;
    std::vector<Arc>    m_arcsList; //Liste des arcs issuent de cet etat;
};



//************************************           OPERATEURS       ************************************************/
bool operator==(State const& , State const& );








#endif // STATE_H_INCLUDED
