#ifndef NODEASTER_H
#define NODEASTER_H



#include <ostream>


template <typename TIPO>
class NodoAster
{
public:
    NodoAster(int);
   ~NodoAster();
    TIPO *getClaves() const;
    void setClaves(TIPO *value);

    int getLlavesUsadas() const;
    void setLlavesUsadas(int value);

    NodoAster<TIPO> **getHijos() const;
    void setHijos(NodoAster<TIPO> **value);

    NodoAster<TIPO> *getPadre() const;
    void setPadre(NodoAster<TIPO> *value);

private:
    int llavesUsadas;
    TIPO *Claves;
    NodoAster<TIPO> **Hijos;
   NodoAster<TIPO> *Padre;
};

#endif // NODEASTER_H
