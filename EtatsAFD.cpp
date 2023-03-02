#include "etatsafd.h"
using namespace std;

/*************************************CONSTRUCTORS & DESTRUCTOS***********************************************/
EtatsAFD::EtatsAFD(State st, std::vector<State> vs){
    this->m_stateAfd = st;
    this->m_list = vs;
}
EtatsAFD::~EtatsAFD(){}
/***************************************    GETTERS & SETTERS     ********************************************/
State EtatsAFD::getStateAfd(){
    return this->m_stateAfd;
}
State EtatsAFD::getStateAfd()const{
    return this->m_stateAfd;
}
std::vector<State> EtatsAFD::getStateList(){
    return this->m_list;
}
std::vector<State> EtatsAFD::getStateList() const{
    return this->m_list;
}
/*************************************           FUNCTIONS        ********************************************/




/*************************************           Operators        ********************************************/
bool operator==(std::vector<State> const& v1, std::vector<State> const& v2){
    if(v1.size() != v2.size())
        return false;
    for(size_t i=0; i<v1.size(); i++)
        if(   !(v1[i] == v2[i])   )
            return false;

    return true;
}
