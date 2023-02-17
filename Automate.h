#ifndef AUTOMATE_H_INCLUDED
#define AUTOMATE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "State.h"
#include "StateNotFoundException.h"


class Automate{

public:
    /*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
    Automate();
    Automate(State* initialState, std::vector<State> sl); //constructeur de copie d'un tableau d'etat;
    ~Automate();

    /***************************************    GETTERS & SETTERS   **********************************************/
    State* getInicialState()const;
    std::vector<State> getStatesListe()const;
    int getSize()const;
    void setInitial(int name);
    void setInitial(State &state);

    /*************************************           FONCTIONS       *********************************************/
    Automate* cloner_automate(Automate const &a);
    /////////////////////////////////////////ajouts
    int add_state();
    void add_state(State &st);
    void add_arc(int name, Arc& a);                      //ajoute un arc a un etat
    void add_arc(int name, char symbol, int destination);
    void remove_state(int name);                         //\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
    void remove_state(State &st);                         //\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
    void remove_arc(int from, int to, char symbol);      //\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
    void remove_arc(State &st, Arc &a);
    /////////////////////////////////////////recherches
    bool searchState(State const& st);
    State* searchState(int name);
    bool searchArc(int from, Arc const& a);
    Arc* searchArc(int from, int to, char symbol);
    /////////////////////////////////////////affichage
    void showAutomate()const;
    void setFinal(State &st);






private:
    /*************************************Variables Membres*******************************************************/
    State*              m_initialState;  //ptr sur l'etat inicial ;
    std::vector<State>  m_statesList;    //liste des etats
};

#endif // AUTOMATE_H_INCLUDED