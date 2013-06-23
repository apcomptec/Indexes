#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include "fileHandling/RecordDataType.h"
#include "dataType/IData.h"
#include "util/Converter.h"
#include "HashElement.h"

using namespace std;

class HashTable:public IData{

public:
    HashTable();        // Constructor
    ~HashTable();       // Destructor

//******************************************************************************
    virtual bool equals( IData &pData1, IData &pData2 );
    virtual bool higher( IData &pData1, IData &pData2 );
    virtual bool lower( IData &pData1, IData &pData2 );
    virtual bool noEquals( IData &pData1, IData &pData2 );
//******************************************************************************
    void insertData(std::string pKey, DLL<IRecordDataType *> *pList);            // Inserción en tabla hash
    bool insertData_AUX( string pKey, DLL<IRecordDataType *> *pList);              // Inserción AUX en tabla hash
    void deleteData(std::string pKey , int pDato);  // Borrado en tabla hash
    void searchData( std::string pKey );            // Búsqueda en tabla hash
    int hashFuntion( std::string pKey );            // Función Hash
    void printHashTable();                          // Impresión en tabla hash

    const std::vector<HashElement*> *getArray() const;   // Retorna una tabla hash
    void setArray(std::vector<HashElement*> *array );    // Modifica una tabla hash

    int getContador() const;
    void setContador(int contador);

private:
    //HashElement *_array;              // Tabla Hash que contendrá HashElements
    vector<HashElement*> *_array;       // Tabla Hash que contendrá HashElements
    Converter *_conversor;              // Conversor de tipos de datos
    int VECTOR_SIZE;                    // Tamaño del vector
    int _contador;

};

#endif // HASHTABLE_H
