#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string input;
    cout << "Enter postfix expression: ";
    getline(cin, input);
    stack<int> st;
    string token = "";

    for (int i=0;i<=input.length();i++)
    {
        if (i==input.length() || input[i]==' ')
        {
            if (!token.empty())
            {
                if (isdigit(token[0]) || (token.size()>1 && token[0]=='-'))
                {
                    int num = 0;
                    int sign = 1;
                    int start = 0;
                    if (token[0]=='-')
                    {
                        sign = -1;
                        start = 1;
                    }
                    for (int j=start;j<token.length(); j++)
                    {
                        num=num*10+(token[j]-'0');
                    }
                    st.push(sign*num);
                }
                else
                {
                    int val1 = st.top();
                    st.pop();
                    int val2 = st.top();
                    st.pop();
                    if (token=="+")
                    {
                        st.push(val2 + val1);
                    }
                    else if (token=="-")
                    {
                        st.push(val2 - val1);
                    }
                    else if (token=="*")
                    {
                        st.push(val2 * val1);
                    }
                    else if (token=="/")
                    {
                        st.push(val2 / val1);
                    }
                }
                token = "";
            }
        }
        else if (input[i]!=' ')
        {
            token+=input[i];
        }
    }

    cout << "Result: " << st.top() << endl;
    return 0;
}