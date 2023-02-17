#include "StateNotFoundException.h"

using namespace std;

//initialisation de la variable de classe;
int StateNotFoundException::num = 0;


/*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
StateNotFoundException::StateNotFoundException(int id, std::string msg) : m_id(id), m_msg(msg){
     StateNotFoundException::num ++;
}
StateNotFoundException::~StateNotFoundException(){}

/***************************************    GETTERS & SETTERS   **********************************************/
int StateNotFoundException::getId(){
    return this->m_id;
}
void StateNotFoundException::setId(int id){
    this->m_id = id;
}
std::string StateNotFoundException::getMsg(){
    return this->m_msg;
}
void StateNotFoundException::setMsg(std::string msg){
    this->m_msg = msg;
}
void StateNotFoundException::print(){
    cout<<"\n\n"
        <<this->num<<"-"
        <<"StateNotFoundException : "
        <<this->m_msg
        <<" <-> No = "<<this->m_id<<endl;
}
