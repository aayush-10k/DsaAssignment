#include <iostream>
#include <stack>
using namespace std;
int main() {
    string s;
    cout << "Enter expression: ";
    cin >> s;

    stack<char> st;
    bool ch = true;
    for (char c : s) 
    {
        if (c == '(' || c == '{' || c == '[') 
        {
            st.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') 
        {
            if (st.empty()) 
            {
                ch = false;
                break;
            }
            char t = st.top();
            st.pop();
            if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '['))
            {
                ch = false;
                break;
            }
        }
    }
    if (!st.empty()) ch = false;
    if (ch) 
    {
        cout << "Balanced";
    } 
    else 
    {
        cout << "Not Balanced";
    }
    return 0;
}
