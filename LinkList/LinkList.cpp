// LinkList.cpp : Defines the entry point for the application.
//

#include "LinkList.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};

ListNode* insertback(ListNode* A, int B) {
    ListNode* newNode = new ListNode(B);
    if (A == NULL) {
        return newNode;
    }
    //ListNode* temp = A;
    //while (temp->next != NULL) {
    //    temp = temp->next;
    //}
    newNode->next = A;
    return newNode;
    //temp = newNode;
    //return A;
}

ListNode* InsertNth(ListNode* A, int B, int C) {
    ListNode* newNode = new ListNode(B);
    if (C == 0) {
        newNode->next = A;
        return newNode;
    }
    int i = 0;
    ListNode* temp = A;
    while (i < C -1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return A;
}

ListNode* deleteNode(ListNode* A, int B) {
    int i = 0;
    ListNode* temp = A;
    if (B == 0) {
        ListNode* nextNode = temp->next;
        delete(temp);
        return nextNode;
    }
    while (i < B - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL) {
        return A;
    }
    ListNode* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete(nodeToDelete);
    return A;
}

void printList(ListNode* A) {
    while (A != NULL) {
        std::cout << A->val << " ";
        A = A->next;
    }
}

int main()
{
	cout << "Hello CMake.\n" << endl;
    ListNode* head = NULL;
    head = insertback(head, 6);
    head = insertback(head, 3);
    head = insertback(head, 3);
    head = insertback(head, 6);
    head = insertback(head, 7);
    head = insertback(head, 8);
    head = insertback(head, 7);
    head = insertback(head, 3);
    head = insertback(head, 7);
    printList(head);
    cout << "\n";
    head = InsertNth(head, 3, 5);
    printList(head);
    head = deleteNode(head, 5);
    cout << "\n";
    printList(head);
	return 0;
}
