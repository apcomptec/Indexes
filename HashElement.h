#ifndef HASHELEMENT_H
#define HASHELEMENT_H

#include <iostream>
#include "dataStructure/DLLNode.h"
#include "dataStructure/DLL.h"
#include "dataStructure/INode.h"
#include "fileHandling/RecordDataType.h"

using namespace std;

class HashElement{

public:
    HashElement();                                              // Constructor
    //~HashElement();                                             // Destructor
    HashElement* getNextHashElement();                          // Obtiene el siguiente nodo
    void setNextHashElement( HashElement *pNextHashElement );   // Cambia el siguiente nodo

    DLL<IRecordDataType *> *getUserDataList() const;                       // Obtiene la info del usuario
    void setUserDataList(DLL<IRecordDataType *> *pList);             // Cambia el info del usuario

    int getBullshit() const;
    void setBullshit(int value);
    void printBullshit();

    bool getDeletedElement() const;
    void setDeletedElement(bool deletedElement);

private:
    DLL<IRecordDataType *> *_list;              // Lista con los datos introducidos por en usuario
    HashElement *_nextHashElement;  // siguiente HashElement (lista simple)
    bool _deletedElement;           // Dice si el elemento existe en o no
    int bullshit;

};

#endif // HASHELEMENT_H
