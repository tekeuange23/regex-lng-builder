#ifndef AUTOMATE_H
#define AUTOMATE_H


#include "State.h"
#include "etatsafd.h"
#include <stack>
#define TAILLEALPHA 100

class Automate{

public:
    /*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
    Automate();
    Automate(std::vector<char> alpha);
    Automate(State* initialState, std::vector<State> sl); //constructeur de copie d'un tableau d'etat;
    Automate(State* initialState, std::vector<State> sl, std::vector<char> alpha);
    Automate(Automate const& a);                          //constructeur de copie
    ~Automate();

    /***************************************    GETTERS & SETTERS   **********************************************/
    State* getInicialState()const;
    std::vector<State> getStatesList()const;
    int getSize()const;
    void setInitial(int name);
    void setInitial(State &state);
    std::vector<char> getAlphabet();
    void setAlphabet(std::vector<char>);

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
    size_t searchStatee(State const& st);
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


    ///////                      TRANSITER :::::::: e_FERMETURES                       ///////
    std::vector<State> transiter(std::vector<State> vst, char symbol);
    std::vector<int>  transite(State st, char symbol);
    std::vector<State> e_fermeture(std::vector<State> vst);


    Automate* determinise();



private:
    /*************************************Variables Membres*******************************************************/
    State*              m_initialState;  //ptr sur l'etat inicial ;
    std::vector<State>  m_statesList;    //liste des etats
    std::vector<char>   m_alphabet;
};



//************************************           OPERATORS       ************************************************/

Automate* operator/(Automate &, Automate &);    //OR
Automate* operator%(Automate &, Automate &);    //DOT
Automate* operator~(Automate &);                //STAR
//Automate* operator+(Automate &);                //PLUS
//Automate* operator?(Automate &);                //INTERROGATION



bool isInStack(std::stack<State> pil, State const& st);
void stactToVector(std::vector<State> &v, std::stack<State> pil);
void showStack(std::stack<State> pil);
void showVector(std::vector<State> v);

bool appartient(std::vector<EtatsAFD> const& vea, std::vector<State> const& v);
bool haveFinal(std::vector<State> const& v);
State* returnStateAfd(std::vector<EtatsAFD> const& vea, std::vector<State> const& v);



#endif // AUTOMATE_H
