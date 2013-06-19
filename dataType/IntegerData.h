#ifndef INTEGERDATA_H
#define INTEGERDATA_H

#include "dataType/IData.h"

class IntegerData: public IData{

public:
    IntegerData();
    ~IntegerData();

    virtual bool equals(IntegerData &pData1, IntegerData &pData2 );
    virtual bool noEquals(IntegerData &pData1, IntegerData &pData2 );
    virtual bool higher( IntegerData &pData1, IntegerData &pData2 );
    virtual bool lower( IntegerData &pData1, IntegerData &pData2 );

    int getData();

private:
    int _dataInteger;
};

#endif // INTEGERDATA_H
