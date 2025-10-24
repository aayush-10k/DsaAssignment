#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter element to search: ";
    cin >> x;
    int l=0,r=n-1,mid,f=-1;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (arr[mid]==x)
        {
            f=mid;
            break;
        }
        else if(arr[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    if (f!=-1)
    {
        cout << "Element found at index: "<<f<<endl;
    }
    else
    {
        cout <<"Element not found"<<endl;
    }
}