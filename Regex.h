#ifndef REGEX_H
#define REGEX_H


#include "Automate.h"
#include "Op.h"
#include "Pile.h"
#include "PileAutomate.h"


class Regex{

public:
    /*************************************CONSTRUCTORS & DESTRUCTOS********************************************/
    Regex(std::string str);
    ~Regex();
    /***************************************    GETTERS & SETTERS     ********************************************/
    const char* getCharList()const;
    /*************************************           FUNCTIONS        ********************************************/
    ////////PILE D'AUTOMATE
    std::vector<Op> infixe();
    bool parenthesage();
    bool verification();
    std::vector<char> alphabet();
    std::vector<Op> posfixe();

    void showString();
    void showInfixe();
    void showPosfixe();

    ////////PILE D'AUTOMATE
    Automate* evaluate();
private:
    /*************************************Variables Membres*******************************************************/
    std::string m_string;
 };


#endif // REGEX_H
