#include "HashTable.h"

HashTable::HashTable()
{
    this->VECTOR_SIZE = 10;              // tamaño de la tabla hash
    this->_array = new std::vector<HashElement*>(VECTOR_SIZE);
    this->_conversor = new Converter();
}

/**
 * @brief HashTable::getArray
 * @return array de hash
 */
const std::vector<HashElement *> *HashTable::getArray() const
{
    return _array;
}

/**
 * @brief HashTable::setArray
 * @param array
 */
void HashTable::setArray(std::vector<HashElement *> *array)
{
    this->_array = array;
}

int HashTable::getContador() const
{
    return _contador;
}

void HashTable::setContador(int contador)
{
    _contador = contador;
}

//******************************************************************************
bool HashTable::equals(IData &pData1, IData &pData2)
{
}

bool HashTable::higher(IData &pData1, IData &pData2)
{
}

bool HashTable::lower(IData &pData1, IData &pData2)
{
}

bool HashTable::noEquals(IData &pData1, IData &pData2)
{
}
//******************************************************************************
/**
 * @brief HashTable::insertData
 * @param pKey
 */
void HashTable::insertData(string pKey, DLL<IRecordDataType *> *pList)//, const DLL<INode *> &list
{
    _contador++;
    if(insertData_AUX(pKey, pList) == true){
        cout << "FIN de inserción en nodo existente" << endl;
    }
    else{
        int vectorIndex = hashFuntion( pKey );
        HashElement *tmp = new HashElement();
        tmp->setUserDataList( pList );
        tmp->setBullshit( _contador );
        if ((*this->_array)[vectorIndex] == NULL){
            cout << "varas" << endl;
            (*this->_array)[vectorIndex] = tmp;
            cout << tmp << endl;
            HashElement *p = (*this->_array)[vectorIndex];
            cout << p << endl;
            cout << p->getBullshit() << endl;
        }
        else{
            cout << "varasDAV " << tmp->getBullshit() << endl;
            HashElement *p = (*this->_array)[vectorIndex];
            while( p->getNextHashElement() != NULL ){
                p = p->getNextHashElement();
            }
            p->setNextHashElement( tmp );
            cout << tmp << endl;
        }
    }
}

/**
 * @brief HashTable::insertData_AUX
 * @param pKey
 * @return
 * Inserta en un nodo que anteriormente ha sido borrado
 */
bool HashTable::insertData_AUX(string pKey, DLL<IRecordDataType *> *pList)
{
    int vectorIndex = hashFuntion( pKey );
    HashElement *tmp = new HashElement();
    tmp = (*this->_array)[vectorIndex];
    while( tmp != 0 ){
        if( tmp->getDeletedElement() == true ){
            tmp->setDeletedElement( false );
            tmp->setUserDataList( pList );
            cout << "AUX el dato: " << pKey << endl;
            return true;
        }
        tmp = tmp->getNextHashElement();
    }
    return false;
}

/**
 * @brief HashTable::deleteData
 * @param pKey
 * @param pDato
 */
void HashTable::deleteData( string pKey, int pDato )
{
    cout << endl;
    int vectorIndex = hashFuntion( pKey );
    cout << "Borrado del dato " << pKey << "," << pDato << " en la tabla HASH" << endl;
    HashElement *tmp = new HashElement();
    tmp = (*this->_array)[vectorIndex];
    while( tmp != 0 ){
        if( tmp->getBullshit() == pDato ){
            tmp->setDeletedElement( true );
            cout << "BORRADO el dato: " << pDato << endl;
            break;
        }
        tmp = tmp->getNextHashElement();
    }
}

/**
 * @brief HashTable::searchData
 * @param pKey
 */
void HashTable::searchData( string pKey )
{
    cout << endl;
    int vectorIndex = hashFuntion( pKey );
    cout << "Busqueda del dato " << pKey << " en la tabla HASH" << endl;
    HashElement *tmp = new HashElement();
    tmp = (*this->_array)[vectorIndex];
    while( tmp != 0 ){
        if (!tmp->getDeletedElement()){
            cout << tmp->getBullshit() << endl;
        }
        tmp = tmp->getNextHashElement();
    }
}

/**
 * @brief HashTable::hashFuntion
 * @param pKey
 * @return Una llave que indicará la posición del dato en la tabla
 */
int HashTable::hashFuntion( string pKey )
{
    QString index = _conversor->fromStringToQString(pKey);
    if ( _conversor->verificaValidezDouble(index) ){
        return -1;
    }
    else if ( _conversor->verificaValidezInt(index) ){
        int value = _conversor->fromString2Int( pKey );
        return value % 10;
    }
    else{   // el dato es string u otro tipo
        char p = pKey.at(0);
        int value = p;
        return value % 10;
    }
}

/**
 * @brief HashTable::printHashTable
 * Imprime la tabla hash!!
 */
void HashTable::printHashTable()
{
    cout << endl;
    cout << "Impresión de datos de la tabla HASH" << endl;
    HashElement *tmp = new HashElement();
    for (int i = 0; i <= VECTOR_SIZE - 1; i++){
        tmp = (*this->_array)[i];
        while( tmp != 0 ){
            if (!tmp->getDeletedElement()){
                cout << tmp->getBullshit() <<
                        " Datos que el usuario introdujo" << endl;
                DLLNode<IRecordDataType*> *tmp1 = tmp->getUserDataList()->getHeadPtr();
                while( tmp1 != 0 ){

                    cout << tmp1->getData()->getName() << " ";
                    cout << tmp1->getData()->getSize() << endl;
                    tmp1 = tmp1->getNextPtr();
                }
            }
            tmp = tmp->getNextHashElement();
        }
        cout << "Datos en la posición: " << i << " de la tabla" << endl;
    }
}
