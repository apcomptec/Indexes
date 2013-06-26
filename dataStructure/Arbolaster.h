#ifndef ARBOLASTER_H
#define ARBOLASTER_H

#include <iostream>
#include <ostream>
#include <istream>

#include <fstream>	// Libreria de manejo de archivos
//#include <conio>
#include <string.h>
#include "dataStructure/NodeAster.h"
#include "dataStructure/NodeAster.cpp"

class Puntero;



template <typename TIPO>
class ArbolAster
{
public:
    ArbolAster(int);
    ~ArbolAster();
    void Insertar(TIPO);

    void Preorden(bool r=true,NodoAster<TIPO>* nodo=NULL);
    void Eliminar(TIPO dato);
    void Mostrar(NodoAster<TIPO> *nodo);
    //bool cargar( char *file );
    //bool guardar( char *file );
    TIPO Encontrar(TIPO &dato);
    TIPO Buscar(TIPO &Clave);
    void Borrar(TIPO &dato);


public:
    int MaxClaves, MinClaves, MaxClavesRaiz;
    NodoAster<TIPO> *Raiz;
    TIPO auxClaves;
    TIPO auxTrabajadores;
    NodoAster<TIPO> **auxHijos;
    void Podar(NodoAster<TIPO>* nodo);
  //  void guardarPreorden(ostream &out, bool r=true,NodoAster<TIPO>* nodo=NULL);
  //  void cargarPreorden(istream &in, bool r=true,NodoAster<TIPO>* nodo=NULL);






public:
    TIPO *lista;
    NodoAster<TIPO>* *listapunt;
    void Inserta(TIPO &Clave, NodoAster<TIPO>* nodo, NodoAster<TIPO>* hijo1, NodoAster<TIPO>* hijo2);
    void BorrarClave(NodoAster<TIPO>* nodo, TIPO &);
    void BorrarNodo(NodoAster<TIPO>* nodo);
    void PasarClaveDerecha(NodoAster<TIPO>* derecha, NodoAster<TIPO>* padre, NodoAster<TIPO>* nodo, int posClavePadre);
    void PasarClaveIzquierda(NodoAster<TIPO>* izquierda, NodoAster<TIPO>* padre, NodoAster<TIPO>* nodo, int posClavePadre);
    void FundirNodo(NodoAster<TIPO>* izquierda, NodoAster<TIPO>* &padre, NodoAster<TIPO>* derecha, int posClavePadre);
    void Ver(NodoAster<TIPO>* nodo);

    int nClaves, nodosMinimos;

};

#endif // ARBOLASTER_H
