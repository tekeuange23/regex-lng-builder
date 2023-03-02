#ifndef ARCNOTFOUNDEXCEPTION_H
#define ARCNOTFOUNDEXCEPTION_H

#include <iostream>
#include <string>

class ArcNotFoundException{
public:
    /*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
    ArcNotFoundException(int id, std::string msg);
    ~ArcNotFoundException();
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


#endif // ARCNOTFOUNDEXCEPTION_H
