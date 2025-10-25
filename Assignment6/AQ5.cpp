#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

bool isCircular(Node *head)
{
    if (head==NULL)
        return true;

    Node *curr = head;
    while (curr!=NULL && curr->next != head)
        curr = curr->next;

    if (curr==NULL)
        return false;

    return true;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    if (isCircular(head))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
