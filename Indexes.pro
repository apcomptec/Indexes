TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
QT +=  core

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    dataType/StringData.cpp \
    dataType/IntegerData.cpp \
    dataType/DoubleData.cpp \
    util/Converter.cpp \
    util/Encryption.cpp \
    util/randomnumber.cpp \
    raid/raid0.cpp \
    raid/Disk.cpp \
    fileHandling/binaryStruct/BTRecordFileMetadata.cpp \
    fileHandling/binaryStruct/BTRecordFile.cpp \
    fileHandling/binaryStruct/BTRecord.cpp \
    dataStructure/HashElement.cpp \
    dataStructure/HashTable.cpp \
    dataStructure/Btree.cpp

HEADERS += \
    HashTable.h \
    dataStructure/DLLNode.h \
    dataStructure/DLL.h \
    dataType/StringData.h \
    dataType/IntegerData.h \
    dataType/IData.h \
    dataType/DoubleData.h \
    dataStructure/INode.h \
    util/Converter.h \
    dataStructure/INode.h \
    dataStructure/DLLNode.h \
    dataStructure/DLL.h \
    example/bplustree/BPlusTree.h \
    util/randomnumber.h \
    util/Encryption.h \
    raid/raid0.h \
    raid/IRaid.h \
    raid/Disk.h \
    fileHandling/RecordDataType.h \
    fileHandling/IRecordFile.h \
    fileHandling/IRecordDataType.h \
    fileHandling/IRecord.h \
    fileHandling/IMetadata.h \
    fileHandling/binaryStruct/BTRecordFileMetadata.h \
    fileHandling/binaryStruct/BTRecordFile.h \
    fileHandling/binaryStruct/BTRecord.h \
    dataStructure/HashElement.h \
    dataStructure/Node.h \
    dataStructure/Btree.h

OTHER_FILES += \
    doc/Indexes_UML.xmi \
    doc/Indexes_UML.pdf

LIBS += -lboost_system-mt -lboost_filesystem-mt

unix: CONFIG += link_pkgconfig
