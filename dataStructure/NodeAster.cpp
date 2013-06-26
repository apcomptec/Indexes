#include "dataStructure/NodeAster.h"

template <typename TIPO>
NodoAster<TIPO>::NodoAster(int numClaves)
{
   llavesUsadas = 0;
   Claves = new TIPO[numClaves];
   Hijos = new NodoAster<TIPO>*[numClaves+1];
   Padre = nullptr;

}

template <typename TIPO>
NodoAster<TIPO>::~NodoAster()
{
   delete[] Claves;
   delete[] Hijos;
}

template <typename TIPO>
int NodoAster<TIPO>::getLlavesUsadas() const
{
    return llavesUsadas;
}

template <typename TIPO>
void NodoAster<TIPO>::setLlavesUsadas(int value)
{
    llavesUsadas = value;
}

template <typename TIPO>
TIPO *NodoAster<TIPO>::getClaves() const
{
    return Claves;
}

template <typename TIPO>
void NodoAster<TIPO>::setClaves(TIPO *value)
{
    Claves = value;
}

template <typename TIPO>
NodoAster<TIPO> *NodoAster<TIPO>::getPadre() const
{
    return Padre;
}

template <typename TIPO>
void NodoAster<TIPO>::setPadre(NodoAster<TIPO> *value)
{
    Padre = value;
}

template <typename TIPO>
NodoAster<TIPO> **NodoAster<TIPO>::getHijos() const
{
    return Hijos;
}

template <typename TIPO>
void NodoAster<TIPO>::setHijos(NodoAster<TIPO> **value)
{
    Hijos = value;
}
