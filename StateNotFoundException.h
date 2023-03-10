#ifndef STATENOTFOUNDEXCEPTION_H
#define STATENOTFOUNDEXCEPTION_H


#include <iostream>
#include <string>

class StateNotFoundException{
public:
    /*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
    StateNotFoundException(int id, std::string msg);
    ~StateNotFoundException();
    /***************************************    GETTERS & SETTERS   **********************************************/
    int getId();
    void setId(int id);
    std::string getMsg();
    void setMsg(std::string msg);
    void print();

//variables de classe
    static int num;
private:
    int m_id;
    std::string m_msg;
};



#endif // STATENOTFOUNDEXCEPTION_H
