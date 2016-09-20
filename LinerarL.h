//
// Created by stone on 2016/9/17.
//

#include "DataType.h"

#ifndef DS_2_LINKLIST_LINERARL_H
#define DS_2_LINKLIST_LINERARL_H

#endif //DS_2_LINKLIST_LINERARL_H

typedef struct node {
    DataType data;
    struct node *next;
    /*bool operator == (const node &n){
        if(data == n.data){
            return true;
        }else{
            return false;
        }

    }*/
} Node, *LinkList;