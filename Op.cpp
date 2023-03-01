#include "Op.h"
using namespace std;

/***************************************CONSTRUCTORS & DESTRUCTOS*********************************************/
Op::Op(char value)                : m_value(value),    m_isOperator(false),    m_priority(0),    m_card(0){}
Op::Op(char value, bool isOperat) : m_value(value),    m_isOperator(isOperat), m_priority(0),    m_card(0){

    if(isOperat){
        if     (value == '/'){
            m_priority = 1;
            m_card     = 2;
        }
        else if(value == '+'){
            m_priority = 1;
            m_card     = 2;
        }
        else if(value == '.'){
            m_priority = 2;
            m_card     = 2;
        }
        else if(value == '*'){
            m_priority = 3;
            m_card     = 1;
        }
        else if(value == '('){
            m_priority = 4;
            m_card     = 0;
        }
        else if(value == ')'){
            m_priority = 4;
            m_card     = 0;
        }
    }

}
Op::Op(Op const& op)    : m_value(op.m_value),    m_isOperator(op.m_isOperator),    m_priority(op.m_priority),    m_card(op.m_card){}
Op::~Op(){}
/***************************************    GETTERS & SETTERS     ********************************************/
char Op::getValue(){
    return this->m_value;
}
bool Op::getOperator(){
    return this->m_isOperator;
}
int  Op::getPrio(){
    return this->m_priority;
}
int  Op::getCard(){
    return this->m_card;
}
/*************************************           FUNCTIONS        ********************************************/





bool isOperantor(char ch){
    return ch=='*' || ch=='/' || ch=='+' || ch=='.' || ch=='(' || ch==')';
}
