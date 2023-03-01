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
////////PILE D'OP
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
        case '*':
            if((i+1)<strlen(chaine) && (!isOperantor(chaine[i+1]) || chaine[i+1]=='(')){
                                                                                                //le cas ou on      a*b   ou a*(b)
                ol.push_back(*(new Op('*',true)));
                ol.push_back(*(new Op('.',true)));
            }
            else if((i+1)<strlen(chaine) && (chaine[i+1]=='/' || chaine[i+1]=='+' || chaine[i+1]=='.' || chaine[i+1]==')')){
                                                                                                //le cas ou on a*/b  a*.b  (a*)
                ol.push_back(*(new Op('*',true)));
            }
            else if((i+1)==strlen(chaine)){                                 //si il se trouve a la derniere case
                ol.push_back(*(new Op('*',true)));
            }
            break;
        case ')':
            if((i+1)<strlen(chaine) && (!isOperantor(chaine[i+1]) || chaine[i+1]=='(')){                                    //si ce qui suit c'est une operande on l'ajoute avec le point
                ol.push_back(*(new Op(')',true)));
                ol.push_back(*(new Op('.',true)));
            }
            else if((i+1)<strlen(chaine) && (chaine[i+1]=='*' || chaine[i+1]=='/' || chaine[i+1]!='+' || chaine[i+1]!='.' || chaine[i+1]!=')')){
                                                                                                //le cas ou on      (a).b   (a)/b   (a)*b   ((a))
                ol.push_back(*(new Op(')',true)));
            }
            else if((i+1)==strlen(chaine)){                                                                               //et si ce qui suit est un operateur
                ol.push_back(*(new Op(')',true)));
            }
            break;
        default:     /**on est dans le cas de:          Operande           */
            if((i+1)<strlen(chaine) && !isOperantor(chaine[i]) && (!isOperantor(chaine[i+1]) || chaine[i+1] == '(')){
                                                                                                //le cas ou on ab  ou  a(b)
                ol.push_back(*(new Op(chaine[i])));
                ol.push_back(*(new Op('.',true)));
            }
            else if((i+1)<strlen(chaine) && !isOperantor(chaine[i]) && (chaine[i+1] == '*') || chaine[i+1] == '/' || chaine[i+1] == '+' || chaine[i+1] == '.' || chaine[i+1] == ')'){
                                                                                                //le cas ou on ab  ou  a/b  a.b  a*b  (a)
                ol.push_back(*(new Op(chaine[i])));
            }
            else if((i+1)==strlen(chaine) && !isOperantor(chaine[i])){                          //si on se trouve a la derniere case
                ol.push_back(*(new Op(chaine[i])));
            }
        }
    }
    return ol;
}
bool Regex::parenthesage(std::vector<Op> ol){
    Pile *pil = new Pile();
    ol = this->infixe();

    for(int i=0; i<ol.size(); i++){
        if(ol[i].getValue()=='(')
            pil->empiler(ol[i]);
        else if(ol[i].getValue()==')'   &&   pil->pileVide())
            return false;
        else if(ol[i].getValue()==')')
            pil->depiler();
    }
    return pil->pileVide();
}
bool Regex::verification(std::vector<Op> ol){
    ol = this->infixe();
    if(!this->parenthesage(ol))         return false;

    /**tests preliminaires**/

    /**tests en profondeur**/
    for(int i=0; i<ol.size(); i++){
        switch (ol[i].getValue()){
        case '*':
            if(i==0) return false;                                                             //ne doit pas de retrouver l'etoile au debut
            else if(ol[i-1].getOperator() && ol[i-1].getValue()!=')') return false;  //       |'a'|--|')'|    '*'
            break;
        case '/':
            if(i==0)                    return false;                                                                    //on ne dois pas avoir un operateur binaire au debut
            else if(i+1 == ol.size())   return false;                                                                    //on ne dois pas avoir un operateur binaire a la fin
            else if(ol[i-1].getOperator() && ol[i-1].getValue()!=')' && ol[i-1].getValue()!='*')return false;  //     |')'|--|'*'|--|'a'|  '/'
            else if(ol[i+1].getOperator() && ol[i+1].getValue()!='(')                           return false;  //                    '/'  |'('|--|'b'|
            break;
        case '.':
            if(i==0)                    return false;                                                                    //on ne dois pas avoir un operateur binaire au debut
            else if(i+1 == ol.size())   return false;                                                                    //on ne dois pas avoir un operateur binaire a la fin
            else if(ol[i-1].getOperator() && ol[i-1].getValue()!=')' && ol[i-1].getValue()!='*')return false;  //     |')'|'*'|'a'|  '.'
            else if(ol[i+1].getOperator() && ol[i+1].getValue()!='(')                           return false;  //                    '.'  |'('|'b'|
            break;
        default:
            break;
        }
    }
    return true;

}
std::vector<Op> Regex::posfixe(){

    Pile* pil = new Pile();
    vector<Op> pol;                     //postfix op list
    vector<Op> iol = this->infixe();
    if(!verification(iol))
            return pol;

    for(int i=0; i<iol.size(); i++){

        if(!iol[i].getOperator())                                                                               //si c'est une operande
            pol.push_back(iol[i]);                                                                                  /**j'affiche*/
        else{                                                                                                   //si c'est une operande
            recommencer:

            if(pil->pileVide())                                                                                     //et pile vide
                pil->empiler(iol[i]);                                                                                   /**j'empile*/
            else{                                                                                                   //et pile !vide
                if(   (  iol[i].getPrio() > pil->getSommet().getPrio() &&  iol[i].getValue()!=')'  )
                                                                        ||  pil->getSommet().getValue()=='(')           //et si la priorite du sommet est inferieur
                    pil->empiler(iol[i]);                                                                                   /**j'empile*/
                else if(    iol[i].getValue() != ')'    ){                                                              //sinon si et je ne suis pas sur )
                    pol.push_back(pil->depiler2());                                                                         /**j'affiche l'operateur depiler*/
                    //pil->empiler(iol[i]);                                                                                   /**j'empile*/
                    //on empile plus
                    goto recommencer;
                    /**              2*3^4-1   ===>>>  2 3 4 ^ * 1 -     faire le test pour comprendre              **/
                    /**      stack ::  * ^ -   ce qui est faut d'oui il faut depiler 2fois avant d'ajouter le -     **/
                }
                else if(    iol[i].getValue()==')'  ){                                                                  //sinon
                    while(pil->getSommet().getValue() != '(')                                                               //tant que le sommet n'est pas sur (
                        pol.push_back(pil->depiler2());                                                                         /**j'affiche l'operateur depiler*/
                    pil->depiler();                                                                                         /**on retire la parenthese ouvrante correspondante*/
                }
            }
        }
    }
    //on vide la pile
    while(!pil->pileVide())                                                                                 //tant que la pile n'est pas vide
        pol.push_back(pil->depiler2());                                                                         /**j'affiche l'operateur depiler*/

    return pol;
}

void Regex::showString(){
    cout<<endl<<"Chaine de caratere : "<<this->m_string
        <<"\t\t___"<<m_string.size()<<endl;
}
void Regex::showInfixe(){

    vector<Op> ol = this->infixe();
    cout<<"Chaine INFIXEE : ";
    for(int i=0; i<ol.size(); i++)
        //cout<<ol[i].getValue();
        cout<<"||"<<ol[i].getValue()<<","<<(ol[i].getOperator() ? "true" : "false")<<"||__";
    //cout<<"\n"<<(this->parenthesage(ol) ? "true" : "false")
    //    <<"\n"<<(this->verification(ol) ? "true" : "false")
    //    <<endl;
    cout<<"\t\t___"<<ol.size()<<endl;
}
void Regex::showPosfixe(){

    vector<Op> ol = this->posfixe();
    cout<<"Chaine POSTFIXE : ";
    for(int i=0; i<ol.size(); i++)
        cout<<ol[i].getValue();
        //cout<<"||"<<ol[i].getValue()<<","<<(ol[i].getOperator() ? "true" : "false")<<"||__";
    //cout<<"\n"<<(this->parenthesage(ol) ? "true" : "false")
    //    <<"\n"<<(this->verification(ol) ? "true" : "false")
    //    <<endl<<endl;
    cout<<"\t\t___"<<ol.size()<<endl<<endl;
}

////////PILE D'AUTOMATE
Automate Regex::evaluation(){
    PileAutomat* pil = new PileAutomat();
    cout<<"nbre: "<<pil->nbreElement()<<"\n";
    vector<Op> pol = this->posfixe();

    Automate *a1=0,
             *a2=0,
             *result=0;
    cout<<"1 "<<pol.size()<<"\n";
    for(int i=0; i<pol.size(); i++){

        if(!pol[i].getOperator()){/**Operande**/

                a1 = a1->thompson(pol[i].getValue());   //creation de l'automate
                pil->empiler(*a1);                      //on empile
                cout<<"2\n";
        }
        else{/**Operateur**/
                switch(pol[i].getValue()){
                    case '/':               //on depile 2 elementa, on effectue l'operation et on empile le resultat
                        a2 = pil->depiler2();
                        a1 = pil->depiler2();
                        result = (*a1) / (*a2);          //le OR
                        pil->empiler(*result);
                        break;
                    case '.':               //on depile 2 elementa, on effectue l'operation et on empile le resultat
                        a2 = pil->depiler2();
                        a1 = pil->depiler2();
                        result = (*a1) % (*a2); //le DOT
                        pil->empiler(*result);
                        break;
                    case '*':               //on depile 1 element,  on effectue l'operation et on empile le resultat
                        a2 = pil->depiler2();
                        result = ~(*a2);     //le STAR
                        pil->empiler(*result);
                        break;
                }
        }
    }
    cout<<"nbre: "<<pil->nbreElement()<<"\n";
    return pil->getSommet();
}


