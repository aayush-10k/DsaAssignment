#include <iostream>
#include <queue>
using namespace std;

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    queue<char> q;
    int freq[26] = {0};

    for (int i=0; i<str.length();i++) 
    {
        char ch=str[i];
        freq[ch-'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front()-'a']>1) 
        {
            q.pop();
        }
        if (q.empty())
            cout<<-1<<" ";
        else
            cout<<q.front()<<" ";
    }
    return 0;
}
