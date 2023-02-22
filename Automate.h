#ifndef AUTOMATE_H_INCLUDED
#define AUTOMATE_H_INCLUDED

#include "State.h"


class Automate{

public:
    /*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
    Automate();
    Automate(State* initialState, std::vector<State> sl); //constructeur de copie d'un tableau d'etat;
    ~Automate();

    /***************************************    GETTERS & SETTERS   **********************************************/
    State* getInicialState()const;
    std::vector<State> getStatesList()const;
    int getSize()const;
    void setInitial(int name);
    void setInitial(State &state);

    /*************************************           FONCTIONS       *********************************************/
    Automate* cloner_automate(Automate const &a);
    /////////////////////////////////////////ajouts
    int add_state();
    void add_state(State &st);
    void add_arc(int name, Arc& a);                      //ajoute un arc a un etat
    void add_arc(int from, int to, char symbol);
    void remove_state(int name);                         //\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
    void remove_state(State &st);                        //\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
    void remove_arc(int from, int to, char symbol);      //\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
    void remove_arc(State &st, Arc &a);
    void setFinal(State &st);
    void unsetSetFinal();
    /////////////////////////////////////////recherches
    bool searchState(State const& st);
    std::vector<State>::iterator searchStat(State const& st);   //retourne la position de l'etat dans le StateList
    State* searchState(int name);
    State* searchFinal();
    bool searchArc(int from, Arc const& a);
    std::vector<Arc>::iterator searchAr(int from, Arc const& a);
    Arc* searchArc(int from, int to, char symbol);
    /////////////////////////////////////////affichage
    void showAutomate()const;




    ///////         THOMPSON'S BUILDINGS :::::::: AN AUTOMATE MATCH TO A REGEX         ///////
    Automate* thompson(char symbol);
    Automate* thompson_or(Automate &a1, Automate &a2);
    Automate* thompson_concat(Automate &a1, Automate &a2);
    Automate* thompson_star(Automate &a1);






private:
    /*************************************Variables Membres*******************************************************/
    State*              m_initialState;  //ptr sur l'etat inicial ;
    std::vector<State>  m_statesList;    //liste des etats
};



//************************************           OPERATORS       ************************************************/

Automate* operator/(Automate &, Automate &);    //OR
Automate* operator,(Automate &, Automate &);    //DOT
Automate* operator~(Automate &);                //STAR
//Automate* operator+(Automate &);                //PLUS
//Automate* operator?(Automate &);                //QUESTION



#endif // AUTOMATE_H_INCLUDED
