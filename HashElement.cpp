#include "HashElement.h"

HashElement::HashElement()
{
    this->bullshit = 0;
    this->_nextHashElement = NULL;
    this->_deletedElement = false;
}

/**
 * @brief HashElement::setNextHashElement
 * Cambia el siguiente "nodo" de la lista simple
 * @param pNextHashElement
 */
void HashElement::setNextHashElement( HashElement *pNextHashElement )
{
    this->_nextHashElement = pNextHashElement;
}

/**
 * @brief HashElement::getNextHashElement
 * Obtiene el siguiente "nodo" de la lista
 * @return
 */
HashElement* HashElement::getNextHashElement()
{
    return this->_nextHashElement;
}

/**
 * @brief HashElement::getUserDataList
 * @return
 */
DLL<IRecordDataType *> *HashElement::getUserDataList() const
{
    return _list;
}

/**
 * @brief HashElement::setUserDataList
 * @param list
 */
void HashElement::setUserDataList(DLL<IRecordDataType *> *pList)
{
    this->_list = pList;
}

int HashElement::getBullshit() const
{
    return bullshit;
}

void HashElement::setBullshit(int value)
{
    bullshit = value;
}

void HashElement::printBullshit()
{
    cout << bullshit << endl;
}

bool HashElement::getDeletedElement() const
{
    return _deletedElement;
}

void HashElement::setDeletedElement(bool deletedElement)
{
    _deletedElement = deletedElement;
}
