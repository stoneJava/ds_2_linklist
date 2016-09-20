#include <iostream>
#include "LinerarL.h"

using namespace std;

LinkList InitiateLinkList() {
//    void *malloc(long NumBytes)：该函数分配了NumBytes个字节，
// 并返回了指向这块内存的指针。如果分配失败，则返回一个空指针（NULL）。
    LinkList head;
    head = (LinkList) malloc(sizeof(Node));
    head->next = NULL;
    return head;

}

//获取链表长度
int LengthLinkList(LinkList head) {
    //指针赋值，不修改地址？
    Node *p = head;
    Node *p1 = p;
    int cnt = 0;
    while (p->next != NULL) {
        p = p->next;
        cnt++;
    }

    return cnt;
}

void addLinkList(LinkList head, DataType x) {


    //在最前面添加
   /* Node *tmp = head;
    Node *next = tmp->next;
    Node *p;
    p = (Node *) malloc(sizeof(Node));
    p->data = x;
    p->next = next;
    head->next = p;*/

    //链表结尾插入
    Node *tmp = head,*p;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    p = (Node *) malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    tmp ->next = p;

}

Node *getLinkList(LinkList head, int i) {
    Node *node = head;
    int num = 0;
    while (node->next != NULL) {
        node = node->next;
        num++;
        if (i == num) {
            return node;
        }
    }
    return NULL;
}

void insertLinkList(LinkList head, DataType x, int i) {

    Node *p = head;
    Node *addNode = (Node *) malloc(sizeof(Node));
    addNode->data = x;
    int num =1;
    while(p->next!=NULL){
        if(num == i-1){
            Node *tmp = p->next;
            Node *nextNode = tmp->next;
            tmp->next =addNode;
            addNode->next = nextNode;
        }
        p=p->next;
        num++;
    }
    /*Node *p, *q;
    if (i == 1) {
        //头结点
        q = head;
    } else {
        q = getLinkList(head, i - 1);
    }
    p = (Node *) malloc(sizeof(Node));
    p->data = x;
    p->next = q->next;
    q->next = p;*/


}

void deleteLinkList(LinkList head ,int i){
    Node * node = head;
    int num =1 ;
    while (node->next!=NULL){
        if(i == num){
            Node *delNode  = node->next;
            Node *currNode = delNode->next;
            node->next = currNode;
            free(delNode);
        }
        node = node->next;
        num ++;
    }
}

int main() {

    /*int c = 5;
    int d = 3;
    int *a =&c;
    int *b = a;

    *b=9;
    a = &d;
    cout << *a << "\t" << *b << "\t" << c << endl;*/

    //初始化
    LinkList linkList = InitiateLinkList();
    DataType x1 = {"王涛", "男", 20, 589};
    DataType x2 = {"潘小欣", "女", 21, 580};
    DataType x3 = {"张艳", "女", 19, 568};
    addLinkList(linkList, x1);
    addLinkList(linkList, x2);
    addLinkList(linkList, x3);

    //获取指定索引的结点
    Node *searchNode = getLinkList(linkList, 1);
    printf("%s \n", searchNode->data.name);

    //结点插入到指定索引位置
    DataType x4 = {"刘勇", "男", 22, 585};
    insertLinkList(linkList, x4, 4);
    Node *searchNode1 = getLinkList(linkList, 4);
    printf("%s \n", searchNode1->data.name);

    //删除结点
    deleteLinkList(linkList,1);
    printf("\n");
    Node *pNode = linkList;
    while(pNode ->next){
        printf("%s",pNode->next->data.name);
        pNode = pNode->next;
    }
    int count = LengthLinkList(linkList);
    printf("%d \n", count);
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}