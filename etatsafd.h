#ifndef ETATSAFD_H
#define ETATSAFD_H

//#include "Automate.h"
#include "State.h"

class EtatsAFD
{
public:
    /*************************************CONSTRUCTORS & DESTRUCTOS***********************************************/
    EtatsAFD(State st, std::vector<State> vs) ;
    ~EtatsAFD();
    /***************************************    GETTERS & SETTERS     ********************************************/
    State getStateAfd();
    State getStateAfd()const;
    std::vector<State> getStateList();
    std::vector<State> getStateList()const;
    /*************************************           FUNCTIONS        ********************************************/

private:
    /*************************************Variables Membres*******************************************************/
    State m_stateAfd;
    std::vector<State> m_list;
};




/*************************************           Operators        ********************************************/
bool operator==(std::vector<State> const&, std::vector<State> const&);






#endif // ETATSAFD_H
