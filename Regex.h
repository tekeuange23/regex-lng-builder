#ifndef REGEX_H_INCLUDED
#define REGEX_H_INCLUDED

#include "Automate.h"
#include "Op.h"
#include "Pile.h"
#include "PileAutomat.h"


class Regex{

public:
    /*************************************CONSTRUCTORS & DESTRUCTOS********************************************/
    Regex(std::string str);
    ~Regex();
    /***************************************    GETTERS & SETTERS     ********************************************/
    const char* getCharList()const;
    /*************************************           FUNCTIONS        ********************************************/
    std::vector<Op> infixe();
    bool parenthesage(std::string ch);
    bool verification(std::string ch);
    std::vector<Op> posfixe();

    void showString();
    void showInfixe();
    void showPosfixe();
private:
    /*************************************Variables Membres*******************************************************/
    std::string m_string;
 };


#endif // REGEX_H_INCLUDED