#ifndef OP_H_INCLUDED
#define OP_H_INCLUDED

#include <iostream>
#include <string>
#include <string.h>

class Op{

public:
    /*************************************CONSTRUCTORS & DESTRUCTOS********************************************/
    Op(char value);
    Op(char value, bool isOperat);
    ~Op();
    /***************************************    GETTERS & SETTERS     ********************************************/
    char getValue();
    bool getOperator();
    /*************************************           FUNCTIONS        ********************************************/


private:
    /*************************************Variables Membres*******************************************************/
    char m_value;
    bool m_isOperator;
 };


bool isOperantor(char ch);


#endif // OP_H_INCLUDED
