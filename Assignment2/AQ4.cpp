#include <iostream>
using namespace std;

int main()
{
    cout << "Part (a) \n";
    char s1[200], s2[100];
    cout << "Enter the first string: ";
    cin.getline(s1, 200);
    cout << "Enter the second string: ";
    cin.getline(s2, 100);

    int i=0, j=0;
    while(s1[i] != '\0')
    {
        i++;
    }
    while(s2[j] != '\0')
    {
        s1[i]=s2[j];
        i++;
        j++;
    }
    s1[i]='\0';
    cout << "Concatenated string: " << s1 << endl;

    cout << "Part (b) \n";
    char r[200];
    cout << "Enter a string to reverse: ";
    cin.getline(r, 200);
    int n=0;
    while(r[n] != '\0')
    {
        n++;
    }
    for(int k=0; k < n / 2; k++)
    {
        char t=r[k];
        r[k]=r[n-k-1];
        r[n-k-1]=t;
    }
    cout << "Reversed string: " << r << endl;

    cout << "Part (c) \n";
    char s[200];
    cout << "Enter a string to remove vowels: ";
    cin.getline(s, 200);
    j=0;
    for(int k=0; s[k] != '\0'; k++)
    {
        char c=s[k];
        if ((c != 'a' && c != 'A' && c != 'e' && c != 'E' && c != 'i' && c != 'I' && c != 'o' && c != 'O' && c != 'u' && c != 'U'))
        {
            s[j]=s[k];
            j++;
        }
    }
    s[j]='\0';
    cout << "String without vowels: " << s << endl;

    cout << "Part (d) \n";
    int m;
    cout << "Enter number of strings to sort: ";
    cin >> m;
    cin.ignore();   
    char arr[m][100];
    for(int k=0; k < m; k++)
    {
        cout << "Enter string " << k + 1 << ": ";
        cin.getline(arr[k], 100);
    }
    for(i=0;i<m-1;i++)
    {
        for(j=i+1;j<m;j++)
        {
            int k=0;
            while(arr[i][k] != '\0' && arr[j][k] != '\0' && arr[i][k] == arr[j][k])
            {
                k++;
            }
            if (arr[i][k] > arr[j][k])
            {
                char temp[100];
                int p=0;
                while(arr[i][p] != '\0')
                {
                    temp[p]=arr[i][p];
                    p++;
                }
                temp[p]='\0';
                p=0;
                while(arr[j][p] != '\0')
                {
                    arr[i][p]=arr[j][p];
                    p++;
                }
                arr[i][p]='\0';
                p=0;
                while(temp[p] != '\0')
                {
                    arr[j][p]=temp[p];
                    p++;
                }
                arr[j][p]='\0';
            }
        }
    }

    cout << "Sorted strings:\n";
    for(int i=0; i < m; i++)
    {
        cout << arr[i] << endl;
    }

    cout << "Part (e) \n";
    char str1[200];
    cout << "Enter a string in Uppercase to convert to Lowercase: ";
    cin.getline(str1, 200);
    j=0;
    while(str1[j] != '\0')
    {
        if (str1[j] >= 'A' && str1[j] <= 'Z')
        {
            str1[j]=str1[j] + 32;
        }
        j++;
    }
    cout << "String in Lowercase is: " << str1;
    return 0;
}
