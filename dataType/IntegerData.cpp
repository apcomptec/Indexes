#include "IntegerData.h"

IntegerData::IntegerData()
{
}

/**
 * @brief IntegerData::equals
 * @param pData1
 * @param pData2
 * @return true si es igual, false en otro caso
 */
bool IntegerData::equals( IntegerData &pData1, IntegerData &pData2 )
{
    if ( pData1.getData() ==  pData2.getData() ){
        return true;    // Datos son iguales
    }
    else{
        return false;   // Datos son diferentes
    }
}

/**
 * @brief IntegerData::noEquals
 * @param pData1
 * @param pData2
 * @return true si es diferente, false en otro caso
 */
bool IntegerData::noEquals( IntegerData &pData1, IntegerData &pData2 )
{
    if ( pData1.getData() !=  pData2.getData() ){
        return true;    // Datos son diferentes
    }
    else{
        return false;   // Datos son iguales
    }
}

/**
 * @brief IntegerData::higher
 * @param pData1
 * @param pData2
 * @return true si el primer dato es mayor, false en otro caso
 */
bool IntegerData::higher( IntegerData &pData1, IntegerData &pData2 )
{
    if( pData1.getData() > pData2.getData() ){
        return true;    // Primer dato es mayor
    }
    else{
        return false;   // Primer dato es menor
    }
}

/**
 * @brief IntegerData::lower
 * @param pData1
 * @param pData2
 * @return true si el primer dato es menor, false en otro caso
 */
bool IntegerData::lower( IntegerData &pData1, IntegerData &pData2 )
{
    if( pData1.getData() < pData2.getData() ){
        return true;    // Primer dato es menor
    }
    else{
        return false;   // Primer dato es mayor
    }
}

/**
 * @brief IntegerData::getData
 * @return el dato
 */
int IntegerData::getData()
{
    return _dataInteger;
}




