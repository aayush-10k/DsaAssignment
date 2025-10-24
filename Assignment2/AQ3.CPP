#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n (range 1 to n): ";
    cin >> n;

    int arr[n-1];
    cout << "Enter " << n-1 << " elements of the array: ";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    // Linear search
    int missing = -1;
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n-1; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            missing = i;
            break;
        }
    }
    cout << "Missing number: " << missing << endl;

    // Binary search

    int low = 0, high = n - 2;
    int missing2 = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    missing2 = low + 1;
    cout << "Missing number: " << missing2 << endl;

    return 0;
}
