#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node {
    int val;
    node* next;
};

node* createList(int num);
void addAtFirst(node*& head, int value);
void addAtLast(node*& head, int value);
void deleteNode(node*& head, int delVal);
void printList(node* head);

#endif // LINKEDLIST_H
