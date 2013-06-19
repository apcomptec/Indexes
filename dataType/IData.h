#ifndef IDATA_H
#define IDATA_H

class IData{

public:
    //  Dice si dos datos son iguales
    virtual bool equals( IData &pData1, IData &pData2 ) = 0;
    //  Dice si el primer dato es mayor que el segundo
    virtual bool higher( IData &pData1, IData &pData2 ) = 0;
    //  Dice si el primer dato es menor que el segundo
    virtual bool lower( IData &pData1, IData &pData2 ) = 0;
    //  Dice si dos datos son diferentes
    virtual bool noEquals( IData &pData1, IData &pData2 ) = 0;

};

#endif // IDATA_H
