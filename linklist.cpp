#include "linkedlist.h"
#include <iostream>

using namespace std;

node* createList(int num) {
    node* head = new node;
    head->val = 1;
    head->next = NULL;
    node* currNode = head;

    for (int i = 1; i < num; ++i) {
        node* newNode = new node;
        newNode->val = i + 1;
        newNode->next = NULL;
        currNode->next = newNode;
        currNode = newNode;
    }
    return head;
}

void addAtFirst(node*& head, int value) {
    node* newFirst = new node;
    newFirst->val = value;
    newFirst->next = head;
    head = newFirst;
}

void addAtLast(node*& head, int value) {
    node* newLast = new node;
    newLast->val = value;
    newLast->next = NULL;
    node* currNode = head;

    while (currNode->next != NULL) {
        currNode = currNode->next;
    }
    currNode->next = newLast;
}

void deleteNode(node*& head, int delVal) {
    if (head->val == delVal) {
        node* delHead = head;
        head = head->next;
        delete delHead;
        return;
    }
    node* temp = head;
    while (temp->next != NULL && temp->next->val != delVal) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }
}

void printList(node* head) {
    node* currNode = head;
    while (currNode != NULL) {
        cout << currNode->val << "->";
        currNode = currNode->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int num, del;
    cout << "How many Nodes do you want to create in the linked list: ";
    cin >> num;

    node* head = createList(num);

    cout << "Original Linked List:" << endl;
    printList(head);

    addAtFirst(head, 115);
    cout << endl << "After adding 115 at the start:" << endl;
    printList(head);

    addAtLast(head, 116);
    cout << endl << "After adding 116 at the end:" << endl;
    printList(head);

    cout << endl << "Enter the value of the node you want to delete: ";
    cin >> del;
    deleteNode(head, del);

    cout << endl << "After deleting " << del << ":" << endl;
    printList(head);

    return 0;
}
