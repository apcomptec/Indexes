#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{
    // TABLA HASH
    cout << "Hello Hash Table!" << endl;
    HashTable *h = new HashTable();
    cout << h->hashFuntion("D") << endl;
    h->insertData("Ana");
    h->insertData("Daniel");
    h->insertData("Dario");
    h->insertData("Dalia");
    h->insertData("Dash");
    h->printHashTable();
    //h->searchData("D");
    h->deleteData("D", 3);
    h->printHashTable();
    h->insertData("Donaldo");
    h->printHashTable();
    return 0;
}

