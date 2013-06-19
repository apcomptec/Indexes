#ifndef INODE_H
#define INODE_H

#include <iostream>
#include "dataStructure/DLL.h"

class INode{

public:

private:
    std::string *_data;
    DLL<std::string> _list;
};

#endif // INODE_H
