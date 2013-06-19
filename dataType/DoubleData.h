#ifndef DOUBLEDATA_H
#define DOUBLEDATA_H

#include "iostream"
#include "dataType/IData.h"

class DoubleData: public IData{

public:
    DoubleData();

    virtual bool equals( DoubleData &pData1, DoubleData &pData2 );
    virtual bool noEquals( DoubleData &pData1, DoubleData &pData2 );
    virtual bool higher( DoubleData &pData1, DoubleData &pData2 );
    virtual bool lower( DoubleData &pData1, DoubleData &pData2 );

    double getData();

private:
    double _dataDouble;
};

#endif // DOUBLEDATA_H
