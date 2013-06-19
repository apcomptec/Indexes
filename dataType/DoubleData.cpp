#include "DoubleData.h"

DoubleData::DoubleData()
{
}

/**
 * @brief DoubleData::equals
 * @param pData1
 * @param pData2
 * @return true si es igual, false en otro caso
 */
bool DoubleData::equals( DoubleData &pData1, DoubleData &pData2 )
{
    if ( pData1.getData() ==  pData2.getData() ){
        return true;    // Datos son iguales
    }
    else{
        return false;   // Datos son diferentes
    }
}

/**
 * @brief DoubleData::noEquals
 * @param pData1
 * @param pData2
 * @return true si es diferente, false en otro caso
 */
bool DoubleData::noEquals( DoubleData &pData1, DoubleData &pData2 )
{
    if ( pData1.getData() !=  pData2.getData() ){
        return true;    // Datos son diferentes
    }
    else{
        return false;   // Datos son iguales
    }
}

/**
 * @brief DoubleData::higher
 * @param pData1
 * @param pData2
 * @return true si el primer dato es mayor, false en otro caso
 */
bool DoubleData::higher( DoubleData &pData1, DoubleData &pData2 )
{
    if( pData1.getData() > pData2.getData() ){
        return true;    // Primer dato es mayor
    }
    else{
        return false;   // Primer dato es menor
    }
}

/**
 * @brief DoubleData::lower
 * @param pData1
 * @param pData2
 * @return true si el primer dato es menor, false en otro caso
 */
bool DoubleData::lower( DoubleData &pData1, DoubleData &pData2 )
{
    if( pData1.getData() < pData2.getData() ){
        return true;    // Primer dato es menor
    }
    else{
        return false;   // Primer dato es mayor
    }
}

/**
 * @brief DoubleData::getData
 * @return el dato
 */
double DoubleData::getData()
{
    return _dataDouble;
}


