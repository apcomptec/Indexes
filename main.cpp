#include <iostream>
#include "dataStructure/HashTable.h"
#include "example/bplustree/BPlusTree.h"
#include "fileHandling/binaryStruct/BTRecordFile.h"
#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "fileHandling/RecordDataType.h"
#include "dataStructure/Btree.h"

using namespace std;

int main(){

//// *****************************************************************************
//// ESTRUCTURA METADATOS
//// *****************************************************************************
//    DLL<IRecordDataType*> *list1 = new DLL<IRecordDataType*>();
//    std::string name1 = "DAV";
//    char dataType1 = '0';
//    unsigned short size1 = 4;
//    RecordDataType<char> *data1 = new RecordDataType<char>(name1, dataType1, size1);
//    list1->insertAtBack(data1);

//    std::string name2 = "IMO";
//    char dataType2 = '3';
//    unsigned short size2 = 2;
//    RecordDataType<char> *data2 = new RecordDataType<char>(name2, dataType2, size2);
//    list1->insertAtBack(data2);

//    BTRecordFileMetadata *metadata = new BTRecordFileMetadata("Fil", "YO", list1);

////// *****************************************************************************
////// CREACIÓN ARCHIVO BINARIO
////// *****************************************************************************
//    BTRecordFile *file = new BTRecordFile(metadata);

//    HashTable *h = new HashTable();
//// *****************************************************************************
//// REGISTRO 1
//// *****************************************************************************
//   {     // CAMPO 'APELLIDO'
//    std::string apellido1 = "H";
//    RecordDataType<std::string> *apellido1Data =
//            new RecordDataType<std::string>(name1, apellido1 , size1);

//    // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//    DLL<IRecordDataType *> *record1 = new DLL<IRecordDataType*>();
//    record1->insertAtBack(apellido1Data);

//    // CAMPO 'GÉNERO'
//    std::string genero1 = "7";
//    RecordDataType<std::string> *genero1Data =
//            new RecordDataType<std::string>(name2, genero1 , size2);

//    // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//    record1->insertAtBack(genero1Data);

//    h->insertData("D", record1);
//    }

//    // *****************************************************************************
//    // REGISTRO 2
//    // *****************************************************************************
//       {     // CAMPO 'APELLIDO'
//        std::string apellido2 = "IMO";
//        RecordDataType<std::string> *apellido1Data =
//                new RecordDataType<std::string>(name2, apellido2 , size2);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        DLL<IRecordDataType *> *record2 = new DLL<IRecordDataType*>();
//        record2->insertAtBack(apellido1Data);

//        // CAMPO 'GÉNERO'
//        std::string genero2 = "5";
//        RecordDataType<std::string> *genero2Data =
//                new RecordDataType<std::string>(name2, genero2 , size2);

//        // INSERTA EL VALOR DEL CAMPO EN LA LISTA DE DATOS DE USUARIO
//        record2->insertAtBack(genero2Data);

//        h->insertData("D", record2);
//        }

//    h->printHashTable();

////    BPlusTree<int, int, 3, 2> b;
////    b.insert(8, 9);
////    b.insert(3, 4);
////    std::cout << b.find(8);
////    std::cout << b.find(2);
//    // TABLA HASH
////    cout << "Hello Hash Table!" << endl;
////    HashTable *h = new HashTable();
////    cout << h->hashFuntion("D") << endl;
////    h->insertData("Ana");
////    h->insertData("Daniel");
////    h->insertData("Dario");
////    h->insertData("Dalia");
////    h->insertData("Dash");
////    h->printHashTable();
////    //h->searchData("D");
////    h->deleteData("D", 3);
////    h->printHashTable();
////    h->insertData("Donaldo");
////    h->printHashTable();
////    return 0;
///
    Btree b ;
    int arr [ ]={30,60,45,8,22,35,4,28,52,33,13,39,41,43,24,
                 25,15};
    int sz = sizeof ( arr ) / sizeof ( int ) ;
    for ( int i = 0 ; i < sz ; i++ )
        b.insert ( arr[i] ) ;
    cout << "arbol B en orden 5:" << endl ;

    b.show( ) ;

    cout<<"\n"<<endl;
}

