#include "Arbolaster.h"
#include "iostream"
#include "fstream"
using namespace std;

template <typename TIPO>
ArbolAster<TIPO>::ArbolAster(int nClv) : nClaves(nClv)
{
   lista = new TIPO[nClaves+1];
   listapunt = new NodoAster<TIPO> *[nClaves+2];
   nodosMinimos = nClaves/2; // ((nClaves+1)/2)-1;
   Raiz = NULL;
}


template <typename TIPO>
ArbolAster<TIPO>::~ArbolAster()
{
   delete[] lista;
   delete[] listapunt;
   // Destruir árbol, algoritmo recursivo:
    Podar(Raiz);
}

template <typename TIPO>
void ArbolAster<TIPO>::Podar(NodoAster<TIPO>* nodo)
{
     int i;

     if(!nodo) return;
     for(i = 0; i <= nodo->getLlavesUsadas(); i++) Podar(nodo->getHijos()[i]);
     delete nodo;
}

//template <typename TIPO>
//void ArbolAster<TIPO>::Mostrar()
//{
//     cout << "arbol" << endl;
//     Ver(Raiz);
//     cout << "-----" << endl;
//     //getch();
//}

template <typename TIPO>
void ArbolAster<TIPO>::Ver(NodoAster<TIPO>* nodo)
{
     int i;

     if(!nodo) return;
     for(i = 0; i < nodo->getLlavesUsadas()-1; i++)
        cout << nodo->getClaves()[i] << "-";
     if(nodo->getLlavesUsadas())
        cout << nodo->getClaves()[i] << " [";
     if(nodo->Padre)
        cout << (nodo->Padre)->getClaves()[0];
    else
        cout << "*";
     cout << "]" << endl;
     for(i = 0; i <= nodo->getLlavesUsadas(); i++) Ver(nodo->getHijos()[i]);
}

template <typename TIPO>
TIPO ArbolAster<TIPO>::Buscar(TIPO &Clave)
{
    NodoAster<TIPO>* nodo = Raiz;
    int i;

    while(nodo)
    {
        i = 0;
        while(i < nodo->getLlavesUsadas() && (nodo->getClaves()[i] < Clave)) i++;
            if(nodo->getClaves()[i] == Clave)
            {
                cout<<i<<endl;
                return &nodo->getClaves()[i];
            }
            else
                nodo = nodo->getHijos()[i];
   }
   return NULL;
}

template <typename TIPO>
void ArbolAster<TIPO>::Insertar(TIPO Clave)
{
   NodoAster<TIPO>* nodo, *Padre;
   int i;

   // Asegurarse de que la Clave no está en el árbol
   Padre = nodo = Raiz;
   while(nodo)
   {
        Padre = nodo;
        i = 0;
        while(i < nodo->getLlavesUsadas() && (nodo->getClaves()[i] < Clave))
            i++;
        if(nodo->getClaves()[i] == Clave && i < nodo->getLlavesUsadas())
        {
            cout<<"\nClave DUPLICADA\n";
            //getch();
            return;
        }
        else
            nodo = nodo->getHijos()[i];
    }

    nodo = Padre;
    Inserta(Clave, nodo, NULL, NULL);
}

template <typename TIPO>
void ArbolAster<TIPO>::Inserta(TIPO &Clave, NodoAster<TIPO>* nodo, NodoAster<TIPO>* hijo1, NodoAster<TIPO>* hijo2)
{
   NodoAster<TIPO>* Padre, *nuevo;
   int i, j;
   bool salir = false;

   // Insertar nueva Clave en nodo:
    do
    {
        if(!nodo)
        {
            nodo = new NodoAster<TIPO>(nClaves);
            nodo->setLlavesUsadas(0);
            nodo->setPadre(nullptr);
            Raiz = nodo;
        }

        Padre = nodo->getPadre();

        if(nodo->getLlavesUsadas() == nClaves) // overflow
        {// Nodo derecho
            nuevo = new NodoAster<TIPO>(nClaves);
            // Construye lista ordenada:
            i = 0;
            while(nodo->getClaves()[i] < Clave && i < nClaves)
            {
                lista[i] = nodo->getClaves()[i];
                listapunt[i] = nodo->getHijos()[i];
                i++;
            }

            lista[i] = Clave;
            listapunt[i] = hijo1;
            listapunt[i+1] = hijo2;

            while(i < nClaves)
            {
                lista[i+1] = nodo->getClaves()[i];
                listapunt[i+2] = nodo->getHijos()[i+1];
                i++;
            }
            // Dividir nodos:
            // Nodo izquierdo:
            nodo->setLlavesUsadas(nClaves/2);
            for(j = 0; j < nodo->getLlavesUsadas(); j++)
            {
                nodo->getClaves()[j] = lista[j];
                nodo->getHijos()[j] = listapunt[j];
            }

            nodo->getHijos()[nodo->getLlavesUsadas()] = listapunt[nodo->getLlavesUsadas()];

            // Nodo derecho:
            nuevo->setLlavesUsadas( nClaves - nodo->getLlavesUsadas());
            for(j = 0; j < nuevo->getLlavesUsadas(); j++)
            {
                nuevo->getClaves()[j] = lista[j+(nClaves/2)+1];
                nuevo->getHijos()[j] = listapunt[j+(nClaves/2)+1];
            }
            nuevo->getHijos()[nuevo->getLlavesUsadas()] = listapunt[nClaves+1];

            for(j = 0; j <= nodo->getLlavesUsadas(); j++)
                if(nodo->getHijos()[j])
                    (nodo->getHijos()[j])->setPadre(nodo);
            for(j = 0; j <= nuevo->getLlavesUsadas(); j++)
                if(nuevo->getHijos()[j])
                    (nuevo->getHijos()[j])->setPadre(nuevo);

            Clave = lista[nClaves/2];
            hijo1 = nodo;
            hijo2 = nuevo;
            nodo = Padre;
        }
        else
        {// Inserta nueva Clave en su lugar:
            i = 0;
            if(nodo->getLlavesUsadas() > 0)
            {
                while(nodo->getClaves()[i] < Clave && i < nodo->getLlavesUsadas()) i++;
                for(j = nodo->getLlavesUsadas(); j > i; j--)
                    nodo->getClaves()[j] = nodo->getClaves()[j-1];
                for(j = nodo->getLlavesUsadas()+1; j > i; j--)
                    nodo->getHijos()[j] = nodo->getHijos()[j-1];
            }

            nodo->setLlavesUsadas(nodo->getLlavesUsadas()+1);
            nodo->getClaves()[i] = Clave;
            nodo->getHijos()[i] = hijo1;
            nodo->getHijos()[i+1] = hijo2;

            if(hijo1)
                hijo1->setPadre(nodo);
            if(hijo2)
                hijo2->setPadre(nodo);
            salir = true;
        }
    }while(!salir);
}

template <typename TIPO>
void ArbolAster<TIPO>::Borrar(TIPO &dato)
{
     // Busca el nodo que contiene la Clave, si existe
    NodoAster<TIPO>* nodo=Raiz;
    int i;
    while(nodo)
    {
        i=0;
        while(i < nodo->getLlavesUsadas() && (nodo->getClaves()[i]< dato))
            i++;

        if(i < nodo->getLlavesUsadas() && nodo->getClaves()[i] == dato)
           break;
        else
            nodo = nodo->getHijos()[i];
    }

    if(nodo) BorrarClave(nodo, dato);
}

template<typename TIPO>
void ArbolAster<TIPO>::BorrarClave(NodoAster<TIPO>* nodo, TIPO &valor)
{
    NodoAster<TIPO>* actual, *derecha, *izquierda, *Padre;
    int posClavePadre, pos, i;

    // Buscar posición dentro de lista de getClaves():
    pos = 0;
    while(nodo->getClaves()[pos] < valor) pos++;

    // ¿Está la Clave en un nodo hoja?
    if(nodo->getHijos()[0])
    { // No, se trata de un nodo intermedio
      // Buscar actual del valor siguiente:
        actual = nodo->getHijos()[pos+1];
        while(actual->getHijos()[0]) actual = actual->getHijos()[0];
        // Intercambiar con el valor siguiente:
        nodo->getClaves()[pos] = actual->getClaves()[0];
        // La posición de la Clave a borrar en ahora la 0:
        pos = 0;
    }
    else
        actual = nodo;

    // Borrar Clave
    for(i = pos; i < actual->getLlavesUsadas(); i++)
        actual->getClaves()[i] = actual->getClaves()[i+1];
    actual->getLlavesUsadas()--;

    if(actual == Raiz && actual->getLlavesUsadas() == 0)
    {
        delete actual;
        Raiz = NULL;
        return;
    }

    // ¿Es el número de getClaves() mayor que el mínimo para el nodo?
    if(actual == Raiz || actual->getLlavesUsadas() >= nodosMinimos)
        return;

    do
    { // El número de getClaves() es menor que el mínimo:
      // Buscar nodos a derecha e izquierda:
        Padre = actual->Padre;
        for(posClavePadre = 0; Padre->getHijos()[posClavePadre] != actual; posClavePadre++);
            if(posClavePadre > 0)
                izquierda = Padre->getHijos()[posClavePadre-1];
            else
                izquierda = NULL;
        if(posClavePadre < Padre->getLlavesUsadas())
            derecha = Padre->getHijos()[posClavePadre+1];
        else
            derecha = NULL;

        // Intentar pasar una Clave de un nodo cercano:
        if(derecha && derecha->getLlavesUsadas() > nodosMinimos)
            PasarClaveDerecha(derecha, Padre, actual, posClavePadre);
        else if(izquierda && izquierda->getLlavesUsadas() > nodosMinimos)
            PasarClaveIzquierda(izquierda, Padre, actual, posClavePadre-1);
        // Si no fue posible, fundir con un nodo cercano y una Clave de padre:
        else if(derecha) // Usar nodo derecho
            FundirNodo(actual, Padre, derecha, posClavePadre);
        else             // Usar el nodo izquierdo
            FundirNodo(izquierda, Padre, actual, posClavePadre-1);
        // Vuelta a empezar:
        actual = Padre;
    }while(actual && actual != Raiz && actual->getLlavesUsadas() < nodosMinimos);
}

template <typename TIPO>
void ArbolAster<TIPO>::PasarClaveDerecha(NodoAster<TIPO>* derecha, NodoAster<TIPO>* Padre, NodoAster<TIPO>* nodo, int posClavePadre)
{
    int i;

    nodo->getClaves()[nodo->getLlavesUsadas()] = Padre->getClaves()[posClavePadre];
    nodo->getLlavesUsadas()++;
    Padre->getClaves()[posClavePadre] = derecha->getClaves()[0];
    nodo->getHijos()[nodo->getLlavesUsadas()] = derecha->getHijos()[0];

    if(derecha->getHijos()[0])
        derecha->getHijos()[0]->Padre = nodo;

    for(i = 0; i < derecha->getLlavesUsadas(); i++)
        derecha->getClaves()[i] = derecha->getClaves()[i+1];
    for(i = 0; i <= derecha->getLlavesUsadas(); i++)
        derecha->getHijos()[i] = derecha->getHijos()[i+1];
    derecha->getLlavesUsadas()--;
}

template <typename TIPO>
void ArbolAster<TIPO>::PasarClaveIzquierda(NodoAster<TIPO>* izquierda, NodoAster<TIPO>* Padre, NodoAster<TIPO>* nodo, int posClavePadre)
{
    int i;

    for(i = nodo->getLlavesUsadas(); i > 0; i--)
        nodo->getClaves()[i] = nodo->getClaves()[i-1];
    for(i = nodo->getLlavesUsadas()+1; i > 0; i--)
        nodo->getHijos()[i] = nodo->getHijos()[i-1];
    nodo->getLlavesUsadas()++;
    nodo->getClaves()[0] = Padre->getClaves()[posClavePadre];
    Padre->getClaves()[posClavePadre] = izquierda->getClaves()[izquierda->getLlavesUsadas()-1];
    nodo->getHijos()[0] = izquierda->getHijos()[izquierda->getLlavesUsadas()];

    if(nodo->getHijos()[0])
        nodo->getHijos()[0]->Padre = nodo;
    izquierda->getLlavesUsadas()--;
}

template <typename TIPO>
void ArbolAster<TIPO>::FundirNodo(NodoAster<TIPO>* izquierda, NodoAster<TIPO>* &Padre, NodoAster<TIPO>* derecha, int posClavePadre)
{
    int i;

    izquierda->getClaves()[izquierda->getLlavesUsadas()] = Padre->getClaves()[posClavePadre];
    Padre->getLlavesUsadas()--;
    for(i = posClavePadre; i < Padre->getLlavesUsadas(); i++)
    {
        Padre->getClaves()[i] = Padre->getClaves()[i+1];
        Padre->getHijos()[i+1] = Padre->getHijos()[i+2];
    }

    izquierda->getLlavesUsadas()++;

    for(i = 0; i < derecha->getLlavesUsadas(); i++)
        izquierda->getClaves()[izquierda->getLlavesUsadas()+i] = derecha->getClaves()[i];
    for(i = 0; i <= derecha->getLlavesUsadas(); i++)
    {
        izquierda->getHijos()[izquierda->getLlavesUsadas()+i] = derecha->getHijos()[i];
        if(derecha->getHijos()[i])
            derecha->getHijos()[i]->Padre = izquierda;
    }

    izquierda->getLlavesUsadas() += derecha->getLlavesUsadas();
    if(Padre == Raiz && Padre->getLlavesUsadas() == 0)
    { // Cambio de Raiz
        Raiz = izquierda;
        Raiz->Padre = NULL;
        delete Padre;
        Padre = NULL;
    }
    delete derecha;
}

//template <typename TIPO>
//TIPO ArbolAster<TIPO>::Encontrar(TIPO dato)
//{
//    NodoAster<TIPO>* nodo=Raiz;
//    int i;
//    while(nodo)
//    {
//        i=0;
//        while(i < nodo->getLlavesUsadas() && (nodo->getClaves()[i]< dato))
//            i++;

//        if(i < nodo->getLlavesUsadas() && nodo->getClaves()[i] == dato)
//           return &nodo->getClaves()[i];
//        else
//            nodo = nodo->getHijos()[i];
//    }
//    return NULL;
//}

//template <typename TIPO>
//bool ArbolAster<TIPO>::guardar( char *file )
//{
//    ofstream out(file);

//    if( !out.fail() )
//        guardarPreorden( out );
//    else
//        return false;
//    out.close();
//    return true;
//}

//template <typename TIPO>
//void ArbolAster<TIPO>::guardarPreorden(ostream &out, bool r,NodoAster<TIPO>* nodo)
//{
//    if(r)
//        nodo=Raiz;
//    if(!nodo)
//        return;

//    for(int i=0;i<nodo->getLlavesUsadas();i++)
//        out<<nodo->getClaves()[i]<<"\t";

//    for(i=0;i<=nodo->getLlavesUsadas();i++)
//        guardarPreorden( out, false,nodo->getHijos()[i]);
//}

//template <typename TIPO>
//bool ArbolAster<TIPO>::cargar( char *file )
//{
//    ifstream in( file );

//    if( !in.fail() )
//    {
//        in>>*this;
///*		//cargarPreorden(in);
//        TIPO dato;
//        in>>dato;
//        do{
//            Insertar(dato);
//            in>>dato;
//        }while(!in.eof());
//*/	}
//    else
//        return false;
//    in.close();
//    return true;
//}

//template <typename TIPO>
//void ArbolAster<TIPO>::cargarPreorden(istream &in, bool r,NodoAster<TIPO>* nodo)
//{
//    if(r)
//        nodo=Raiz;
//    if(!nodo)
//        return;

//    TIPO dato;
//    for(int i=0;i<nodo->getLlavesUsadas();i++)
//    {
//        in>>dato;
//        Insertar(dato);
//        //nodo->getClaves()[i];
//    }

//    for(i=0;i<=nodo->getLlavesUsadas();i++)
//        cargarPreorden( in, false,nodo->getHijos()[i]);
//}

//template <typename TIPO>
//ostream& operator<<(ostream &os, ArbolAster<TIPO> &ab)
//{
//    guardarPreorden( os );
//    return os;
//}

template <typename TIPO>
istream& operator>>(istream &is, ArbolAster<TIPO> &ab)
{
    TIPO dato;
    is>>dato;
    while( !is.eof() )
    {
        ab.Insertar(dato);
        is>>dato;
    }
    return is;
}

template <typename TIPO>
void ArbolAster<TIPO>::Preorden(bool r,NodoAster<TIPO>* nodo)
{
    int i;
    if(r)
        nodo=Raiz;
    if(!nodo)
        return;
    Mostrar(nodo);
    for(i=0;i<=nodo->getLlavesUsadas();i++)
        Preorden(false,nodo->getHijos()[i]);
}

template <typename TIPO>
void ArbolAster<TIPO>::Mostrar(NodoAster<TIPO>* nodo)
{
    for(int i=0;i< nodo->getLlavesUsadas();i++)
        cout<<nodo->getClaves()[i]<<endl;
}

template <typename TIPO>
void ArbolAster<TIPO>::Eliminar(TIPO dato)
{
    NodoAster<TIPO>* nodo=Raiz;
    NodoAster<TIPO>* hoja;
    NodoAster<TIPO>* tmp;
    NodoAster<TIPO>* nodo1;
    NodoAster<TIPO>* nodo2;
    int i,h=0;
    while(nodo)
    {
        i=0;
        while(i < nodo->getLlavesUsadas() && (nodo->getClaves()[i]< dato))
        {
            i++;
            if(i < nodo->getLlavesUsadas() && nodo->getClaves()[i] == dato)
            {
                if(nodo->getHijos()[0]==NULL)//si el nodo a eliminar es hoja
                {
                    hoja=nodo;
                    while(i<nodo->getLlavesUsadas()-1)
                    {
                        nodo->getClaves()[i]=nodo->getClaves()[i+1];
                        i++;
                    }
                    nodo->getLlavesUsadas()--;
                    return;
                }
                if(nodo->getHijos()[0]!=NULL)//si el nodo a eliminar no es hoja pero no tiene descendientes
                {
                    int j=0;
                    nodo1=nodo->getHijos()[i];
                    nodo2=nodo->getHijos()[i+1];
                    if(nodo1->getLlavesUsadas()==MinClaves-1&&nodo2->getLlavesUsadas()==MinClaves-1)
                    {
                        nodo1->getClaves()[MinClaves-1]=nodo2->getClaves()[0];
                        if(nodo2->getHijos()[0]!=NULL)
                        {
                            int a1=0;
                            for(int a=MinClaves-1;a<=2;a++)
                            {
                                a1++;
                                nodo1->getHijos()[a+1]=nodo2->getHijos()[a1];
                            }
                        }
                        nodo->getLlavesUsadas()--;
                        //nodo->Pagina--;
                        nodo2=NULL;
                        cout<<nodo1->getClaves()[1];
                        //numpag--;
                        Insertar(nodo1->getClaves()[1]);
                        return;
                    }
                    if(nodo2->getLlavesUsadas()>nodo1->getLlavesUsadas())
                    {
                        if(nodo2->getLlavesUsadas()!=MinClaves)
                        {
                            h=1;
                            nodo->getClaves()[i]=nodo2->getClaves()[0];
                            while(j<nodo2->getLlavesUsadas()-1)
                            {
                                nodo2->getClaves()[j]=nodo2->getClaves()[j+1];
                                j++;
                            }
                            nodo2->getLlavesUsadas()--;
                        }
                        if(h==1)
                        {
                            h=0;
                            return;
                        }
                    }
                    else
                    {
                        if(nodo1->getLlavesUsadas()!=MinClaves)
                        {
                            h=1;
                            nodo->getClaves()[i]=nodo1->getClaves()[nodo->getLlavesUsadas()-1];
                            nodo2->getLlavesUsadas()--;
                        }
                        if(h==1)
                        {
                            h=0;
                            return;
                        }
                    }
                }
            }
        }
        tmp=nodo;
        nodo = nodo->getHijos()[i];
    }
}
