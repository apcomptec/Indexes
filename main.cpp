#include <iostream>
#include "HashTable.h"
#include "example/bplustree/BPlusTree.h"

using namespace std;

int main()
{

    BPlusTree<int, int, 3, 2> b;
    b.insert(8, 9);
    b.insert(3, 4);
    std::cout << b.find(8);
    std::cout << b.find(2);
    // TABLA HASH
//    cout << "Hello Hash Table!" << endl;
//    HashTable *h = new HashTable();
//    cout << h->hashFuntion("D") << endl;
//    h->insertData("Ana");
//    h->insertData("Daniel");
//    h->insertData("Dario");
//    h->insertData("Dalia");
//    h->insertData("Dash");
//    h->printHashTable();
//    //h->searchData("D");
//    h->deleteData("D", 3);
//    h->printHashTable();
//    h->insertData("Donaldo");
//    h->printHashTable();
    return 0;
}

