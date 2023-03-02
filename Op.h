#ifndef OP_H
#define OP_H



#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


class Op{

public:
    /*************************************CONSTRUCTORS & DESTRUCTOS********************************************/
    Op(char value);
    Op(char value, bool isOperat);
    Op(Op const& op);
    ~Op();
    /***************************************    GETTERS & SETTERS     ********************************************/
    char getValue();
    bool getOperator();
    int  getPrio();
    int  getCard();
    /*************************************           FUNCTIONS        ********************************************/

private:
    /*************************************Variables Membres*******************************************************/
    char m_value;
    bool m_isOperator;
    int m_priority;
    int m_card;         //unaire? binaire? ternaire? ... Nnaire?
 };


bool isOperantor(char ch);





#endif // OP_H
