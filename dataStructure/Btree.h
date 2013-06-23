#ifndef BTREE_H
#define BTREE_H

//#include <Node.h>
#include "dataStructure/Node.h"
#include <iostream>
#include <alloca.h>
#include <stdlib.h>
using namespace std;


class Btree
{
public :
    Node *root ;

public:
    Btree();



    void insert ( int Ipointer ) ;//insert pointer in Btree
    int setIpointer ( int Ipointer, Node *node, int *point, Node **temp ) ;//ubication in tree ,depends your position
    static Node * search ( int Ipointer, Node *root, int *position ) ;//search Ipointer
    static int searchnode ( int Ipointer, Node *node, int *position ) ;//looking for node in the tree
    void fillnode ( int Ipointer, Node *temp, Node *node, int kposition ) ;//fill node ,depends in position
    void split ( int Ipointer, Node *temp, Node *node, int kposition, int *ypos, Node **newnode ) ;//separate the tree
    void erase( int Ipointer ) ;//erase pointer in the tree
    int eraseaux ( int Ipointer, Node *root ) ;//help the search the node for erase the node
    void clear ( Node *root, int kpos ) ;//position clear
    void copy ( Node *root, int i ) ;//funtion aux for copy the node
    void restore ( Node *root, int i ) ;//restore many nodes after erase
    void right( int kpos ) ;//move to the right the node
    void left( int kpos ) ;//move to the left
    void merge ( int kpos ) ;//rotation
    void show( ) ;//print the Btree
    static void display ( Node *root ) ;//help the show the Btree
    static void deltree ( Node *root ) ;//erase all the Btree
    ~Btree( ) ;//Memory

};


#endif // BTREE_H
