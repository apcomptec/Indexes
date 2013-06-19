#include "StringData.h"

StringData::StringData()
{
}

/**
 * @brief StringData::equals
 * @param pData1
 * @param pData2
 * @return true si son iguales, false en otro caso
 */
bool StringData::equals(StringData &pData1, StringData &pData2)
{
    if ( pData1.getData().compare( pData2.getData()) ){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief StringData::noEquals
 * @param pData1
 * @param pData2
 * @return true si son diferentes, false en otro caso
 */
bool StringData::noEquals(StringData &pData1, StringData &pData2)
{
    if ( !pData1.getData().compare( pData2.getData()) ){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief StringData::higher
 * @param pData1
 * @param pData2
 * @return true si el primer dato es mayor, else entre otro caso
 */
bool StringData::higher(StringData &pData1, StringData &pData2)
{
    if ( pData1.getData() >= ( pData2.getData()) ){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief StringData::lower
 * @param pData1
 * @param pData2
 * @return true si el primer dato es menor, else entre otro caso
 */
bool StringData::lower(StringData &pData1, StringData &pData2)
{
    if ( pData1.getData() <= ( pData2.getData()) ){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief StringData::getData
 * @return dato en string
 */
std::string StringData::getData()
{
    return _dataString;
}





