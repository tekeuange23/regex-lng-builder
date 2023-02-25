#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

#include "Arc.h"
#include "StateNotFoundException.h"
#include "ArcNotFoundException.h"

class State{

public:
    /*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
    State();
    State(int name);    //this constructor will be use inside all our methods to avoid the increase of the COMPTER
    State(bool isFinal, std::vector<Arc> al);  //consteucteur de copie d'un tableau d'arcs
    State(bool isFinal);
    ~State();
    /***************************************    GETTERS & SETTERS     ********************************************/
    int getName()const;
    bool getIsFinal()const;
    std::vector<Arc> getArcList()const;
    int getSize()const;
    static int getCompter();


    /*************************************           FONCTIONS        ********************************************/
    ////////////////////////////ajouts
    void add_arc(Arc &a);
    void add_arc(char symbol, int destination);
    void remove_arc(Arc &a);
    void remove_arc(int destination, char symbol);
    void setFinal();
    void unsetFinal();
    ////////////////////////////recherche
    bool searchArc(Arc const& a);
    std::vector<Arc>::iterator searchAr(Arc const& a);
    Arc* searchArc(int destination, char symbol);
    ////////////////////////////affichage
    void showState()const;



private:
    /*************************************Variables Membres*******************************************************/
    int                 m_name;     //nom de l'etat ;
    bool                m_isFinal;  //est ce qu'il est un etat d'acceptation? ;
    std::vector<Arc>    m_arcsList  ; //Liste des arcs issuent de cet etat;
    static int compter;

};



//************************************           OPERATORS       ************************************************/
bool operator==(State const& , State const& );








#endif // STATE_H_INCLUDED
