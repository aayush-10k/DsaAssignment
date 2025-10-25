#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void DisplayCLL(Node* head) {
    if (head == NULL) 
    return;

    Node* curr = head;
    int result = 0;

    do {
        cout<<curr->data<<" ";
        curr = curr->next;
        result++;
    } while (curr != head);
    cout<<curr->data<<" ";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head;

    DisplayCLL(head);

    return 0;
}