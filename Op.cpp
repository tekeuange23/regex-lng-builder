#include "Op.h"
using namespace std;

/***************************************CONSTRUCTORS & DESTRUCTOS*********************************************/
Op::Op(char value)                : m_value(value),    m_isOperator(false)   {}
Op::Op(char value, bool isOperat) : m_value(value),    m_isOperator(isOperat){}
Op::~Op(){}
/***************************************    GETTERS & SETTERS     ********************************************/
char Op::getValue(){
    return this->m_value;
}
bool Op::getOperator(){
    return this->m_isOperator;
}
/*************************************           FUNCTIONS        ********************************************/





bool isOperantor(char ch){
    return ch=='*' || ch=='/' || ch=='+' || ch=='.' || ch=='(' || ch==')';
}
