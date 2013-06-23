#ifndef NODE_H
#define NODE_H

//#endif // NODE_H

#include <iostream>
#include <alloca.h>
#include <stdlib.h>

const int MAX = 4 ;//orden de arbol
const int MIN = 2 ;//orden de minimo


struct Node {
    int count ;//contador
    int value[MAX + 1] ;//valores
    Node *child[MAX + 1] ; //hijos de arbol para acomodo
};

#endif
