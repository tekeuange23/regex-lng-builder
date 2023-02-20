#include "ArcNotFoundException.h"

using namespace std;

//initialisation de la variable de classe;
int ArcNotFoundException::num = 0;


/*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
ArcNotFoundException::ArcNotFoundException(int id, std::string msg) : m_id(id), m_msg(msg){
     ArcNotFoundException::num ++;
}
ArcNotFoundException::~ArcNotFoundException(){}

/***************************************    GETTERS & SETTERS   **********************************************/
int ArcNotFoundException::getId(){
    return this->m_id;
}
void ArcNotFoundException::setId(int id){
    this->m_id = id;
}
std::string ArcNotFoundException::getMsg(){
    return this->m_msg;
}
void ArcNotFoundException::setMsg(std::string msg){
    this->m_msg = msg;
}
void ArcNotFoundException::print(){
    cout<<"\n\n"
        <<this->num<<"-"
        <<"ArcNotFoundException : "
        <<this->m_msg
        <<" <-> No = "<<this->m_id<<endl;
}


