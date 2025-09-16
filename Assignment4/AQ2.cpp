#include <iostream>
using namespace std;

int *arr;
int SIZE;
int front=-1, rear=-1;

bool isEmpty() 
{
    return (front==-1 && rear==-1);
}

bool isFull() 
{
    return ((rear + 1) % SIZE==front);
}

void enqueue(int num) 
{
    if (isFull()) 
    {
        cout<<"Queue is Full!"<<endl;
        return;
    }
    if (isEmpty()) 
    {
        front=rear=0;
    } 
    else 
    {
        rear=(rear+1) % SIZE;
    }
    arr[rear]=num;
    cout<<num<<" inserted into queue"<<endl;
}

void dequeue() 
{
    if (isEmpty()) 
    {
        cout<<"Queue is Empty!"<<endl;
        return;
    }
    cout<<arr[front]<<" removed from queue"<<endl;
    if (front==rear) 
    {
        front=rear=-1;
    } 
    else 
    {
        front=(front + 1) % SIZE;
    }
}

void peek() 
{
    if (isEmpty()) 
    {
        cout<<"Queue is Empty!"<<endl;
    } 
    else 
    {
        cout<<"Front element is: "<<arr[front]<<endl;
    }
}

void display() 
{
    if (isEmpty()) 
    {
        cout<<"Queue is Empty!"<<endl;
    } 
    else 
    {
        cout<<"Queue elements: ";
        int i=front;
        while (true) {
            cout<<arr[i]<<" ";
            if (i==rear) break;
            i=(i + 1) % SIZE;
        }
        cout<<endl;
    }
}

int main() 
{
    int choice, num;
    cout<<"Enter size of queue: ";
    cin >> SIZE;
    arr=new int[SIZE];
    do {
        cout<<"Circular Queue Menu\n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Peek\n";
        cout<<"4. Display\n";
        cout<<"5. Check if Empty\n";
        cout<<"6. Check if Full\n";
        cout<<"7. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout<<"Enter number to insert: ";
            cin >> num;
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty())
                cout<<"Queue is Empty!"<<endl;
            else
                cout<<"Queue is NOT Empty!"<<endl;
            break;
        case 6:
            if (isFull())
                cout<<"Queue is Full!"<<endl;
            else
                cout<<"Queue is NOT Full!"<<endl;
            break;
        case 7:
            cout<<"Exited"<<endl;
            break;
        default:
            cout<<"Invalid choice, try again!"<<endl;
        }
    } while (choice != 7);

    delete[] arr;
    return 0;
}
