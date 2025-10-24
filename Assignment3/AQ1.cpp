#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int stack[MAX_SIZE];
int top = -1;

void push(int value)
{
    if (top >= MAX_SIZE - 1)
    {
        cout << "Stack Overflow! Cannot push " << value << endl;
    }
    else
    {
        top++;
        stack[top] = value;
        cout << "Pushed " << value << " onto the stack" << endl;
    }
}

int pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow! Stack is empty" << endl;
        return -1;
    }
    else
    {
        int value = stack[top];
        top--;
        cout << "Popped " << value << " from the stack" << endl;
        return value;
    }
}

bool isEmpty()
{
    return (top < 0);
}

bool isFull()
{
    return (top >= MAX_SIZE - 1);
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else
    {
        cout << "Top element: " << stack[top] << endl;
        return stack[top];
    }
}

int main()
{
    int choice, value;
    while (true)
    {
        cout << "\tStack Operations Menu" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display Stack" << endl;
        cout << "6. Peek (Top Element)" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            if (isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            break;

        case 4:
            if (isFull())
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
            break;

        case 5:
            display();
            break;

        case 6:
            peek();
            break;

        case 7:
            cout << "Exiting program..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}