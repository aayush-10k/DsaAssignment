#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2; 
queue<int> q;      

void pushTwoQueues(int x) 
{
    q2.push(x);
    while (!q1.empty()) 
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

void popTwoQueues() 
{
    if(q1.empty()) 
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<q1.front()<<" popped from stack"<<endl;
    q1.pop();
}

int topTwoQueues() 
{
    if(q1.empty()) 
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return q1.front();
}

void displayTwoQueues() 
{
    if(q1.empty()) 
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    queue<int> temp=q1;
    cout<<"Stack elements: ";
    while (!temp.empty()) 
    {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
}

void pushOneQueue(int x) 
{
    int sz=q.size();
    q.push(x);
    for (int i=0; i<sz; i++) 
    {
        q.push(q.front());
        q.pop();
    }
}

void popOneQueue() 
{
    if(q.empty()) 
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<q.front()<<" popped from stack"<<endl;
    q.pop();
}

int topOneQueue() 
{
    if(q.empty()) 
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return q.front();
}

void displayOneQueue() 
{
    if(q.empty()) 
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    queue<int> temp=q;
    cout<<"Stack elements: ";
    while (!temp.empty()) 
    {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
}

int main() 
{
    int method, choice, num;
    cout<<"Choose Stack Implementation:\n1. Two Queues\n2. One Queue\nEnter choice: ";
    cin >> method;

    if(method==1) 
    {
        do {
            cout<<"Stack (Two Queues) Menu\n";
            cout<<"1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\nEnter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout<<"Enter element: ";
                    cin >> num;
                    pushTwoQueues(num);
                    break;
                case 2:
                    popTwoQueues();
                    break;
                case 3:
                    cout<<"Top element: "<<topTwoQueues()<<endl;
                    break;
                case 4:
                    displayTwoQueues();
                    break;
                case 5:
                    cout<<"Exited"<<endl;
                    break;
                default:
                    cout<<"Invalid choice"<<endl;
            }
        } while (choice != 5);
    } 
    else if(method == 2) 
    {
        do {
            cout<<"Stack(One Queue)Menu\n";
            cout<<"1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\nEnter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout<<"Enter element: ";
                    cin >> num;
                    pushOneQueue(num);
                    break;
                case 2:
                    popOneQueue();
                    break;
                case 3:
                    cout<<"Top element: "<<topOneQueue()<<endl;
                    break;
                case 4:
                    displayOneQueue();
                    break;
                case 5:
                    cout<<"Exited"<<endl;
                    break;
                default:
                    cout<<"Invalid choice"<<endl;
            }
        } while (choice != 5);
    } 
    else 
    {
        cout<<"Invalid method choice"<<endl;
    }
    return 0;
}
