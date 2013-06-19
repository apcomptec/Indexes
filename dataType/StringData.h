#ifndef STRINGDATA_H
#define STRINGDATA_H

#include <iostream>
#include "dataType/IData.h"

class StringData {

public:
    StringData();

    virtual bool equals( StringData &pData1, StringData &pData2 );
    virtual bool noEquals( StringData &pData1, StringData &pData2 );
    virtual bool higher( StringData &pData1, StringData &pData2 );
    virtual bool lower( StringData &pData1, StringData &pData2 );

    std::string getData();

private:
    std::string _dataString;

};

#endif // STRINGDATA_H
