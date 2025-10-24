#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter size of Diagonal Matrix n: ";
    cin >> n;
    int diagMat[n][n];
    cout << "Enter the " << n << "x" << n << " diagonal matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> diagMat[i][j];
        }
    }
    cout << "Input Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << diagMat[i][j] << " ";
        }
        cout << "\n";
    }
    int diag[n];
    for(int i=0;i<n;i++) 
    {
        diag[i] = diagMat[i][i];
    }
    cout << "Linear storage (Diagonal): ";
    for(int i=0;i<n;i++) 
    {
        cout << diag[i] << " ";
    }
    cout << "\n\n";
    
    cout << "Enter size of Tri-diagonal Matrix n: ";
    cin >> n;
    int triMat[n][n];
    cout << "Enter the " << n << "x" << n << " matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> triMat[i][j];
        } 
    }
    cout << "Input Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << triMat[i][j] << " ";
        }
        cout << "\n";
    }
    int tri[3*n - 2], k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j || i==j+1 || j==i+1)
            {
                tri[k++] = triMat[i][j];
            }
        }
    }
    cout << "Linear storage (Tri-diagonal): ";
    for(int i=0;i<3*n-2;i++) cout << tri[i] << " ";
    cout << "\n\n";

    cout << "Enter size of Lower Triangular Matrix n: ";
    cin >> n;
    int lowMat[n][n];
    cout << "Enter the " << n << "x" << n << " matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> lowMat[i][j];
        } 
    }
    cout << "Input Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << lowMat[i][j] << " ";
        }
        cout << "\n";
    }
    int lower[n*(n+1)/2];
    k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            lower[k++] = lowMat[i][j];
        } 
    }
    cout << "Linear storage (Lower Triangular): ";
    for(int i=0;i<n*(n+1)/2;i++) 
    {
        cout << lower[i] << " ";
    }
    cout << "\n\n";

    cout << "Enter size of Upper Triangular Matrix n: ";
    cin >> n;
    int upMat[n][n];
    cout << "Enter the " << n << "x" << n << " matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) 
        {
            cin >> upMat[i][j];
        }
    }
    cout << "Input Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << upMat[i][j] << " ";
        }
        cout << "\n";
    }
    int upper[n*(n+1)/2];
    k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            upper[k++] = upMat[i][j];
        }
    }
    cout << "Linear storage (Upper Triangular): ";
    for(int i=0;i<n*(n+1)/2;i++) 
    {
        cout << upper[i] << " ";
    }
    cout << "\n\n";

    cout << "Enter size of Symmetric Matrix n: ";
    cin >> n;
    int symMat[n][n];
    cout << "Enter the " << n << "x" << n << " matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) 
        {
            cin >> symMat[i][j];
        }
    }
    cout << "Input Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << symMat[i][j] << " ";
        }
        cout << "\n";
    }
    int sym[n*(n+1)/2];
    k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++) 
        {
            sym[k++] = symMat[i][j];
        }
    }
    cout << "Linear storage (Symmetric): ";
    for(int i=0;i<n*(n+1)/2;i++) 
    {
        cout << sym[i] << " ";
    }
    cout << "\n";

    return 0;
}
