#include "Automate.h"
using namespace std;

/*************************************CONSTRUCTEURS & DESTRUCTEURS********************************************/
Automate::Automate()    :   m_initialState(nullptr){}
Automate::Automate(std::vector<char> alpha)    :   m_initialState(nullptr){
    this->setAlphabet( alpha );
}
Automate::Automate(State* initialState, std::vector<State> sl)    :   m_initialState(nullptr){

    this->m_initialState = initialState;
    this->m_statesList.resize(sl.size());
    for(size_t i=0; i<sl.size(); i++)
        m_statesList[i] = sl[i];
}
Automate::Automate(State* initialState, std::vector<State> sl, std::vector<char> alpha){
    this->m_initialState = initialState;
    this->m_statesList.resize(sl.size());
    for(size_t i=0; i<sl.size(); i++)
        m_statesList[i] = sl[i];
    this->setAlphabet( alpha );
}
Automate::Automate(Automate const& a)    :   m_initialState(nullptr){

    m_initialState = a.m_initialState;

    for(size_t i=0; i<a.m_statesList.size(); i++)
        this->m_statesList.push_back(a.m_statesList[i]);

}
Automate::~Automate(){
    delete m_initialState;
    m_initialState=nullptr;

    m_statesList.clear();
}

/***************************************    GETTERS & SETTERS   **********************************************/
State* Automate::getInicialState()const{
    return this->m_initialState;
}
std::vector<State> Automate::getStatesList()const{
    return m_statesList;
}
int Automate::getSize()const{
    return this->m_statesList.size();
}
void Automate::setInitial(int name){
    try{
        this->m_initialState = searchState(name);
    }catch(StateNotFoundException e){   e.print();    }
}
void Automate::setInitial(State &state){
    this->m_initialState = &state;
}
std::vector<char> Automate::getAlphabet(){
    return this->m_alphabet;
}
void Automate::setAlphabet(std::vector<char> alpha){
    for(size_t i=0; i<alpha.size(); i++){
        this->m_alphabet.push_back(alpha[i]);
    }
}

/*************************************           FONCTIONS       *********************************************/
/////////////////////////////////////////ajouts & suppression
Automate* Automate::cloner_automate(Automate const &a){

    Automate* a1 = new Automate();
    a1->m_initialState = a.m_initialState;
    a1->m_statesList.resize(a.m_statesList.size());
    for(size_t i=0; i<this->m_statesList.size(); i++)
        a1->m_statesList[i] = a.m_statesList[i];
    return a1;
}
int Automate::add_state(){
    State* st = new State();
    this->m_statesList.push_back(*st);

    return st->getName();
}
void Automate::add_state(State &st){
    this->m_statesList.push_back(st);
}
void Automate::add_arc(int name, Arc &a){
    try{
    //cas ou l'etat cherchee n'est pas trouvee
        State* st = this->searchState(name);
        st->add_arc(a);

    }
    catch(StateNotFoundException e){
        e.print();
    }
}
void Automate::add_arc(int from, int to, char symbol){
    try{
        searchState(to);    //on verifi si l'etat de destination existe bel et bien
        Arc* a = new Arc(symbol,to);
        this->add_arc(from,*a);
        cout<<"Ajout reussi arc\n";
    }
    catch(StateNotFoundException e){    e.print();   }

}
void Automate::remove_state(int name){

    try{
        std::vector<State>::iterator     pos    =   searchStat(*(this->searchState(name)) );
        pos->getArcList().clear();  //on suprime tous les arcs de l'etat en question;
        this->m_statesList.erase(pos);
        cout<<"\nl'etat a ete supprimer\n";
    }catch(StateNotFoundException e){    e.print();  }
}
void Automate::remove_state(State &st){
    for(size_t i=0; i<st.getSize(); i++)
        st.remove_arc(st.getArcList()[i]);

    delete &st;
}
void Automate::remove_arc(int from, int to, char symbol){
    try{
        State* st = this->searchState(from);
        st->remove_arc(to,symbol);
    }catch(StateNotFoundException e){   e.print();  }

}
void Automate::remove_arc(State &st, Arc &a){
    st.remove_arc(a);
}
void Automate::setFinal(State &st){
    if(this->searchState(st))   //si l'etat pris en parametre est un etat de l'automate en question
        st.setFinal();
}
void Automate::unsetSetFinal(){
    State* st = this->searchFinal();
    st->unsetFinal();
}
/////////////////////////////////////////recherches
bool Automate::searchState(State const &st){
    for(size_t i=0; i<this->m_statesList.size(); i++)
        if(this->m_statesList[i] == st)
           return true;
    return false;
}
std::vector<State>::iterator Automate::searchStat(State const& st){
    for(std::vector<State>::iterator ptr = m_statesList.begin();  ptr<m_statesList.end(); ptr++)
        if(*ptr == st)
            return ptr;

    StateNotFoundException* error = new StateNotFoundException(399,"You are trying to use a State which is not exist.");
    throw *error;               //l'etat n'ayant pas ete trouve, ceci peut generer une exeption: ON LA LEVE;
}
//size_t Automate::searchStatee(State const& st){}
State* Automate::searchState(int name){
    for(size_t i=0; i<this->m_statesList.size(); i++)
        if(this->m_statesList[i].getName() == name)
           return &(this->m_statesList[i]);

    StateNotFoundException* error = new StateNotFoundException(399,"You are trying to use a State which is not exist.");
    throw *error;               //l'etat n'ayant pas ete trouve, ceci peut generer une exeption: ON LA LEVE;
}
State* Automate::searchFinal(){
    for(size_t i=0; i<this->m_statesList.size(); i++)
        if(this->m_statesList[i].getIsFinal())
           return &(this->m_statesList[i]);

    StateNotFoundException* error = new StateNotFoundException(399,"You are trying to use a State which is not exist.");
    throw *error;               //l'etat n'ayant pas ete trouve, ceci peut generer une exeption: ON LA LEVE;
}
bool Automate::searchArc(int from, Arc const& a){
    try{
        State* s = this->searchState(from);
        s->searchArc(a);
    }catch(ArcNotFoundException e) {    e.print();  }

    return false;
}
std::vector<Arc>::iterator Automate::searchAr(int from, Arc const& a){
    try{
        State* st = this->searchState(from);
        return st->searchAr(a);
    }catch(ArcNotFoundException e) {    e.print();  }
}
Arc* Automate::searchArc(int from, int to, char symbol){
    try{
        State* s = this->searchState(from);
        s->searchArc(to,symbol);
    }catch(ArcNotFoundException e) {    e.print();  }
}
/////////////////////////////////////////affichage
void Automate::showAutomate()const{
    if(this->getInicialState() == nullptr){
        cout<<"\nnull Automate\n"<<endl;
        return;
    }

    cout<<"////////////////////////////////  AUTOMATE  //////////////////////////////////"<<endl<<endl;
    cout<<"\t\t\t"
        <<"Initial State : q"<<this->m_initialState->getName()
        <<endl<<endl;
    for(size_t i=0; i<this->m_statesList.size(); i++)
       this->m_statesList[i].showState();
    cout<<"//////////////////////////////////////////////////////////////////////////////"
        <<this->getSize()<<endl;
}




///////         THOMPSON'S BUILDINGS :::::::: AN AUTOMATE MATCH TO A REGEX         ///////
Automate* Automate::thompson(char symbol){

    Automate* a = new Automate();

    State* i = new State();
    State* f = new State(true);

    a->m_initialState = i;
    a->add_state(*i);
    a->add_state(*f);
    a->add_arc(i->getName(),f->getName(),symbol);

    return a;
}
Automate* Automate::thompson_or(Automate &a1, Automate &a2){
    Automate* a = new Automate();
    State* i = new State();     //new initial STATE
    i->add_arc('e',a1.getInicialState()->getName());
    i->add_arc('e',a2.getInicialState()->getName());
    State* f = new State(true);
    try{
        a1.searchFinal()->add_arc('e',f->getName());
        a1.searchFinal()->unsetFinal();
        a2.searchFinal()->add_arc('e',f->getName());
        a2.searchFinal()->unsetFinal();
    }catch(StateNotFoundException e){   e.print();  }

    a->m_initialState = i;

    a->add_state(*i);
    for(int i=0; i<a1.getSize(); i++)
        a->add_state(a1.getStatesList()[i]);
    for(int i=0; i<a2.getSize(); i++)
        a->add_state(a2.getStatesList()[i]);
    a->add_state(*f);

    return a;
}
Automate* Automate::thompson_concat(Automate &a1, Automate &a2){

    Automate* a = new Automate();

    try{
        a1.searchFinal()->add_arc('e', a2.getInicialState()->getName());    //1
        a1.searchFinal()->unsetFinal();                                     //2
    }catch(StateNotFoundException e){   e.print();   }

    a->m_initialState = a1.getInicialState();
    for(int i=0; i<a1.getSize(); i++)
        a->add_state(a1.getStatesList()[i]);
    for(int i=0; i<a2.getSize(); i++)
        a->add_state(a2.getStatesList()[i]);

    return a;
}
Automate* Automate::thompson_star(Automate &a1){

    Automate* a = new Automate();

    State* i = new State();
    i->add_arc('e',a1.getInicialState()->getName());

    State* f = new State(true);
    try{
        a1.searchFinal()->add_arc('e',f->getName());
        a1.searchFinal()->add_arc('e',a1.getInicialState()->getName());
        a1.searchFinal()->unsetFinal();
    }catch(StateNotFoundException e){   e.print();  }

    i->add_arc('e',f->getName());

    a->m_initialState = i;
    a->add_state(*i);
    for(int i=0; i<a1.getSize(); i++)
        a->add_state(a1.getStatesList()[i]);
    a->add_state(*f);

    return a;
}

///////                                  OPERATORS                                 ///////
Automate* operator/(Automate &a1, Automate &a2){

    Automate* a = nullptr;
    a = a->thompson_or(a1,a2);
    return a;
}
Automate* operator%(Automate &a1, Automate &a2){
    Automate* a = nullptr;
    a = a->thompson_concat(a1,a2);
    return a;
}
Automate* operator~(Automate &a1){
    Automate* a = nullptr;
    a = a->thompson_star(a1);
    return a;
}


///////                      TRANSITER :::::::: e_FERMETURES                       ///////
bool isInStack(std::stack<State> pil, State const& st){
    while(!pil.empty()){
        if(pil.top() == st)
            return true;
        pil.pop();
    }
    return false;
}
void stactToVector(std::vector<State> &v, std::stack<State> pil){
    while(!pil.empty()){
        v.push_back(pil.top());
        pil.pop();
    }
}
void showStack(std::stack<State> pil){
     cout<<"=====================================E_FERMETURE=========================================\n";
     while(!pil.empty()){
        pil.top().showState();
        pil.pop();
     }
}
void showVector(std::vector<State> v){
    cout<<"=====================================TRANSITER============================================\n";
     for(size_t i=0; i<v.size(); i++)
        v[i].showState();
}


std::vector<State> Automate::transiter(std::vector<State> vst, char symbol){

    vector<State> vstate;
    for(size_t i=0; i<vst.size(); i++){
        State etat = *this->searchState(vst[i].getName());
        vector<int> vint = transite( etat, symbol );
        for(size_t j=0; j<vint.size(); j++){
                State etat1 = *this->searchState(vint[j]);
                vstate.push_back(etat1);
        }
    }
    return vstate;
}
std::vector<int> Automate::transite(State st, char symbol){
    vector<int> vint;
    //vint = st.transite(symbol);
    vint = this->searchState(st.getName())->transite(symbol);

        //for(int i=0; i<vint.size(); i++)
        //    cout<<"VINT"<<i+1<<" : "<<vint[i]<<"\t\t";
        //cout<<endl;
        //cout<<"debug : "<<vint.size()<<endl;

    return vint;
}
std::vector<State> Automate::e_fermeture(std::vector<State> vst){

    stack<State>  pileDeTravail;
    stack<State>  PileFinale;

    for(size_t i=0; i<vst.size(); i++){
        pileDeTravail.push(*this->searchState(vst[i].getName()));
        PileFinale.push(*this->searchState(vst[i].getName()));
    }

    while(!pileDeTravail.empty()){
        State* t = new State(pileDeTravail.top());
        pileDeTravail.pop();
        vector<int> vint = this->transite(*this->searchState(t->getName()),'e');
            //for(int i=0; i<vint.size(); i++)
            //    cout<<"VINTe"<<i+1<<" : "<<vint[i]<<"\t\t";
            //cout<<endl;

        for(size_t i=0; i<vint.size(); i++){
            State* u = searchState(vint[i]);  /***/
            if(!isInStack(PileFinale,*u)){
                PileFinale.push(*u);
                pileDeTravail.push(*u);
            }
        }
    }


    vector<State>v;
    stactToVector(v, PileFinale);
    return v;

}


bool appartient(std::vector<EtatsAFD> const& vea, std::vector<State> const& v){
    for(size_t i=0; i<vea.size(); i++){
        if(vea[i].getStateList() == v)
            return true;
    }
    return false;
}
bool haveFinal(std::vector<State> const& v){

    for(size_t i=0; i<v.size(); i++)
        if(v[i].getIsFinal())
            return true;
    return false;
}
State* returnStateAfd(std::vector<EtatsAFD> const& vea, std::vector<State> const& v){
    State* s = nullptr;
    for(size_t i=0; i<vea.size(); i++){
        if(vea[i].getStateList() == v)
            *s = (vea[i].getStateAfd());
    }
    return s;
}

Automate* Automate::determinise(){


    /*
     *
     * Automate *A = new Automate();

    std::vector< vector<State> >  DEtats;
    std::vector<State>            Etats;

        cout<<"A*************\n";
    vector<State> v;
    v.push_back(*this->searchState(this->getInicialState()->getName()));
        cout<<"B*************\n";
    DEtats.push_back(this->e_fermeture( v ));                               //e_ferm(q0)
        cout<<"C*************\n";
    Etats.push_back(*new State());

    vector<State> u;
    State* state;
    for(size_t i=0; i<DEtats.size(); i++){
            cout<<"D*************\n";
            cout<<m_alphabet.size()<<"***************taille du tableau retourner*************\n";
        for(size_t symbol=0;    symbol<this->m_alphabet.size(); symbol++){

            cout<<"E*************\n";
            u = e_fermeture(transiter(DEtats[i], m_alphabet[symbol]));
            if(  !appartient(DEtats, u)  ){
                DEtats.push_back(u);
                bool isFinal=false;
                for(size_t j=0; j<u.size(); j++)
                    if(u[j].getIsFinal())
                        isFinal = true;
                state = new State(isFinal);
                Etats.push_back(*state );
            }
            A->add_state(*state);
            A->add_arc(state->getName(),    m_alphabet[symbol],    Etats[i].getName());
        }
        cout<<"Z*************\n";
    }



    return A;
    */

    Automate* afd = nullptr;
cout<<"\n1";
    std::vector<EtatsAFD> DEtats;

    //e_ferm q0
        vector<State> vs;
        vs.push_back(*this->searchState(this->getInicialState()->getName()));
    State* init = new State();
    EtatsAFD* ea = new EtatsAFD(*init, e_fermeture(vs) );
    DEtats.push_back(*ea);
    //quit est l'etat initial
    //afd->add_state(*init);
    //afd->setInitial(*init);

cout<<"\n2";
    std::stack<EtatsAFD> *pil = nullptr;

    for(size_t i=0; i<DEtats.size(); i++){                                   //tant qu'il n'existe un etat non marquee,
        pil->push(DEtats[i]);                                                //le marque.
        for(size_t symbol = 0; symbol<this->m_alphabet.size(); symbol++){    //pour chaque symbol de l'aphabet
            vs = e_fermeture(transiter(pil->top().getStateList(), this->m_alphabet[symbol]));  //eferm(transite(A,a))
cout<<"\n3";
            if(!appartient(DEtats, vs)      && vs.size() != 0){
                init = new State(haveFinal(vs));                                            /** creation de la destin **/
                pil->top().getStateAfd().add_arc(this->m_alphabet[symbol], init->getName());/** ajout de l'arc symbol **/
                ea = new EtatsAFD(*init, vs);                                               /** creation de l'objet   **/
                DEtats.push_back(*ea);                                                      /** insertion dans DETATS **/
cout<<"\n4";
            }
            else if(appartient(DEtats, vs)  && vs.size() != 0){
                init = returnStateAfd(DEtats,vs);                                           /** recherch de la destin **/
                pil->top().getStateAfd().add_arc(this->m_alphabet[symbol], init->getName());/** ajout de l'arc symbol **/
cout<<"\n5";
            }
            else if(vs.size() == 0){
cout<<"\n6";
            }
        }
    }

    vector<State> vst;
    for(size_t i=0; i<DEtats.size(); i++){      /**  **/
        vst.push_back(DEtats[i].getStateAfd());
    }
cout<<"\n7";

    if(vst.size() != 0)
        afd = new Automate(&vst[0], vst, this->getAlphabet());

    return afd;
}





