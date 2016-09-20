#include <iostream>
#include "LinerarL.h"

using namespace std;

LinkList InitiateLinkList() {
//    void *malloc(long NumBytes)���ú���������NumBytes���ֽڣ�
// ��������ָ������ڴ��ָ�롣�������ʧ�ܣ��򷵻�һ����ָ�루NULL����
    LinkList head;
    head = (LinkList) malloc(sizeof(Node));
    head->next = NULL;
    return head;

}

//��ȡ������
int LengthLinkList(LinkList head) {
    //ָ�븳ֵ�����޸ĵ�ַ��
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


    //����ǰ�����
   /* Node *tmp = head;
    Node *next = tmp->next;
    Node *p;
    p = (Node *) malloc(sizeof(Node));
    p->data = x;
    p->next = next;
    head->next = p;*/

    //�����β����
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
        //ͷ���
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

    //��ʼ��
    LinkList linkList = InitiateLinkList();
    DataType x1 = {"����", "��", 20, 589};
    DataType x2 = {"��С��", "Ů", 21, 580};
    DataType x3 = {"����", "Ů", 19, 568};
    addLinkList(linkList, x1);
    addLinkList(linkList, x2);
    addLinkList(linkList, x3);

    //��ȡָ�������Ľ��
    Node *searchNode = getLinkList(linkList, 1);
    printf("%s \n", searchNode->data.name);

    //�����뵽ָ������λ��
    DataType x4 = {"����", "��", 22, 585};
    insertLinkList(linkList, x4, 4);
    Node *searchNode1 = getLinkList(linkList, 4);
    printf("%s \n", searchNode1->data.name);

    //ɾ�����
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