#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: " << endl;
    for (int i=0;i<n;i++) 
    {
        cin >>arr[i];
    }
    cout << "The array is: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int count=0;
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (arr[i]>arr[j])
            {
                count++;
            }
        }
    }
    cout << "The number of inversions is: " << count << endl;
    return 0;
}
