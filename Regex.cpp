#include "Regex.h"
using namespace std;

/*************************************CONSTRUCTORS & DESTRUCTOS********************************************/
Regex::Regex(std::string str) : m_string(str) {}
Regex::~Regex(){}
/***************************************    GETTERS & SETTERS     ********************************************/
const char* Regex::getCharList()const{
    const char* ch = m_string.c_str();
    return ch;
}
/*************************************           FUNCTIONS        ********************************************/

std::vector<Op> Regex::infixe(){
    const char* chaine = getCharList();
    vector<Op> ol;      //operator list

    for(size_t i=0; i<strlen(chaine); i++){
        switch (chaine[i]){
        case '/':
            ol.push_back(*(new Op('/',true)));
            break;
        case '+':
            ol.push_back(*(new Op('/',true)));
            break;
        case '.':
            ol.push_back(*(new Op('.',true)));
            break;
        case '(':
            ol.push_back(*(new Op('(',true)));
            break;
        case ')':
            ol.push_back(*(new Op(')',true)));
            break;
        default:                                                                        //on est dans le cas ou on a une operande
            if((i+1)<strlen(chaine) && chaine[i]!='*'  && !isOperantor(chaine[i+1])){   //si ce qui suit c'est une operande on l'ajoute avec le point
                ol.push_back(*(new Op(chaine[i],false)));
                ol.push_back(*(new Op('.',true)));
            }
            else if((i+1)<strlen(chaine) && chaine[i]=='*' && !isOperantor(chaine[i+1])){   //le cas ou on * et ensuite une operande
                ol.push_back(*(new Op('*',true)));
                ol.push_back(*(new Op('.',true)));
            }
            else if((i+1)<strlen(chaine) && chaine[i]!='*' && chaine[i+1]=='('){           //si ce qui suit c'est une operande on l'ajoute avec le point
                ol.push_back(*(new Op(chaine[i],false)));
                ol.push_back(*(new Op('.',true)));
            }
            else if((i+1)<strlen(chaine) && chaine[i]=='*' && chaine[i+1]=='('){           //si ce qui suit c'est une operande on l'ajoute avec le point
                ol.push_back(*(new Op('*',true)));
                ol.push_back(*(new Op('.',true)));
            }
            else                                        //et si ce qui suit est un operateur
                ol.push_back(*(new Op(chaine[i],false)));
            break;
        }
    }
    return ol;
}
bool Regex::parenthesage(std::string ch){}
bool Regex::verification(std::string ch){}
std::vector<Op> Regex::posfixe(){}

void Regex::showString(){
    cout<<endl<<"Chaine de caratere : "<<this->m_string<<endl;
}
void Regex::showInfixe(){

    vector<Op> ol = this->infixe();
    cout<<endl<<"Chaine INFIXEE : ";
    for(int i=0; i<ol.size(); i++)
        cout<<ol[i].getValue();
        //cout<<"||"<<ol[i].getValue()<<","<<(ol[i].getOperator() ? "true" : "false")<<"||__";
    cout<<endl<<endl;
}
void Regex::showPosfixe(){}
