#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *next;
    Node *prev;
    Node(char val) {
        data = val;
        next = prev = NULL;
    }
};

bool isPalindrome(Node *head) {
    if (head==NULL) return true;

    Node *tail = head;
    while (tail->next) tail = tail->next;

    Node *front = head;
    while (front != tail && front->prev != tail) {
        if (front->data != tail->data)
            return false;
        front = front->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node *head = new Node('L');
    head->next = new Node('E');
    head->next->prev = head;
    head->next->next = new Node('V');
    head->next->next->prev = head->next;
    head->next->next->next = new Node('E');
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node('L');
    head->next->next->next->next->prev = head->next->next->next;

    if (isPalindrome(head))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
