#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s = "DataStructure";
    stack<char> st;
    for (char c : s)
        st.push(c);
    string res;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    cout << s << endl;
    cout << res << endl;
    return 0;
}
