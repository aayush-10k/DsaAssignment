#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: "<< endl;
    for(int i=0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count=0;
    for(int i=0; i < n; i++) 
    {
        int duplicate=0;
        for(int j=0; j < i; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                duplicate=1;
                break;
            }
        }
        if (duplicate == 0) 
        {
            count++;
        }
    }
    cout << "Number of distinct elements: " << count << endl;
    return 0;
}