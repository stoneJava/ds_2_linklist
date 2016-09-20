//
// Created by stone on 2016/9/17.
//

#ifndef DS_2_LINKLIST_DATATYPE_H
#define DS_2_LINKLIST_DATATYPE_H

#endif //DS_2_LINKLIST_DATATYPE_H

#include <iostream>
#include <cstring>
const int MaxSize = 7;
typedef struct DataType {
    char name[8];
    char sex[3];
    int age;
    int score;

    bool operator==(const DataType &data) {
         if (strcmp(name,data.name) && (age == age)) {
            return true;
        } else {
            return false;
        }
    }
} DataType;