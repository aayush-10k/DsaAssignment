#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

int sizeDLL(Node *head) {
    int count = 0;
    Node *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

int sizeCLL(Node *last) {
    if (last==NULL) 
    return 0;
    int count = 0;
    Node *curr = last->next; 
    Node *head = last->next;
    do {
        count++;
        curr = curr->next;
    } while (curr != head);
    return count;
}

int main() {
    
    Node *dllHead = new Node(1);
    dllHead->next = new Node(2);
    dllHead->next->prev = dllHead;
    dllHead->next->next = new Node(3);
    dllHead->next->next->prev = dllHead->next;
    dllHead->next->next->next = new Node(4);
    dllHead->next->next->next->prev = dllHead->next->next;

    cout << "Size of Doubly Linked List: " << sizeDLL(dllHead) << endl;

    Node *cll1 = new Node(10);
    Node *cll2 = new Node(20);
    Node *cll3 = new Node(30);
    cll1->next = cll2;
    cll2->next = cll3;
    cll3->next = cll1; 
    Node *cllLast = cll3;

    cout << "Size of Circular Linked List: " << sizeCLL(cllLast) << endl;

    return 0;
}
