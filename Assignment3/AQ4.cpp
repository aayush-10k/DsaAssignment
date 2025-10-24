#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter infix expression: ";
    cin >> s;
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            res += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') {
            while (st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            int prec_c;
            if (c == '^')
                prec_c = 3;
            else if (c == '/' || c == '*')
                prec_c = 2;
            else if (c == '+' || c == '-')
                prec_c = 1;
            else
                prec_c = -1;
                
            while (!st.empty()) {
                char top = st.top();
                int prec_top;
                if (top == '^')
                    prec_top = 3;
                else if (top == '/' || top == '*')
                    prec_top = 2;
                else if (top == '+' || top == '-')
                    prec_top = 1;
                else
                    prec_top = -1;
                    
                if (prec_c <= prec_top) {
                    res += st.top();
                    st.pop();
                } else {
                    break;
                }
            }
            st.push(c);
        }
    }
    
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    
    cout << "Postfix expression: " << res << endl;
    return 0;
}