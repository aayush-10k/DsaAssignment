#include <iostream>
using namespace std;

int main()
{
    int r, c;
    int size = 0;
    cout << "Part (a) \n";
    cout << "Enter Row and Column of Original Matrix:" << endl;
    cin >> r >> c;
    int arr[r][c];
    cout << "Enter Matrix elements:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if ((arr[i][j]) != 0)
            {
                size++;
            }
        }
    }
    int sparse_arr[3][size];
    cout << "Original Matrix is:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] != 0)
            {
                sparse_arr[0][k] = i;
                sparse_arr[1][k] = j;
                sparse_arr[2][k] = arr[i][j];
                k++;
            }
        }
    }
    cout << "Sparse Matrix is:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << sparse_arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < size; i++)
    {
        int temp = sparse_arr[0][i];
        sparse_arr[0][i] = sparse_arr[1][i];
        sparse_arr[1][i] = temp;
    }

    cout << "Transpose of Sparse Matrix is:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << sparse_arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Part (b) \n";
    cout << "Enter Row and Column of Matrices:" << endl;
    cin >> r >> c;
    int size_A = 0, size_B = 0;
    int A[r][c];
    int B[r][c];
    cout << "Enter Matrix A elements:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> A[i][j];
            if ((A[i][j]) != 0)
            {
                size_A++;
            }
        }
    }
    int sparse_A[3][size_A];
    cout << "Enter Matrix B elements:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> B[i][j];
            if ((B[i][j]) != 0)
            {
                size_B++;
            }
        }
    }
    int sparse_B[3][size_B];
    cout << "Original Matrix A is:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Original Matrix B is:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (A[i][j] != 0)
            {
                sparse_A[0][k] = i;
                sparse_A[1][k] = j;
                sparse_A[2][k] = A[i][j];
                k++;
            }
        }
    }
    cout << "Sparse of Matrix A is:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size_A; j++)
        {
            cout << sparse_A[i][j] << " ";
        }
        cout << endl;
    }
    k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (B[i][j] != 0)
            {
                sparse_B[0][k] = i;
                sparse_B[1][k] = j;
                sparse_B[2][k] = B[i][j];
                k++;
            }
        }
    }
    cout << "Sparse of Matrix B is:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size_B; j++)
        {
            cout << sparse_B[i][j] << " ";
        }
        cout << endl;
    }
    int size_Sum = 0;
    int Sum[3][size_A + size_B];
    int i = 0, j = 0;
    k = 0;
    while (i < size_A && j < size_B)
    {
        if (sparse_A[0][i] < sparse_B[0][j])
        {
            Sum[0][k] = sparse_A[0][i];
            Sum[1][k] = sparse_A[1][i];
            Sum[2][k] = sparse_A[2][i];
            i++;
            k++;
        }
        else if (sparse_B[0][j] < sparse_A[0][i])
        {
            Sum[0][k] = sparse_B[0][j];
            Sum[1][k] = sparse_B[1][j];
            Sum[2][k] = sparse_B[2][j];
            j++;
            k++;
        }
        else
        {
            if (sparse_A[1][i] < sparse_B[1][j])
            {
                Sum[0][k] = sparse_A[0][i];
                Sum[1][k] = sparse_A[1][i];
                Sum[2][k] = sparse_A[2][i];
                i++;
                k++;
            }
            else if (sparse_B[1][j] < sparse_A[1][i])
            {
                Sum[0][k] = sparse_B[0][j];
                Sum[1][k] = sparse_B[1][j];
                Sum[2][k] = sparse_B[2][j];
                j++;
                k++;
            }
            else
            {
                Sum[0][k] = sparse_A[0][i];
                Sum[1][k] = sparse_A[1][i];
                Sum[2][k] = sparse_A[2][i] + sparse_B[2][j];
                i++;
                j++;
                k++;
            }
        }
    }
    while (i < size_A)
    {
        Sum[0][k] = sparse_A[0][i];
        Sum[1][k] = sparse_A[1][i];
        Sum[2][k] = sparse_A[2][i];
        i++;
        k++;
    }
    while (j < size_B)
    {
        Sum[0][k] = sparse_B[0][j];
        Sum[1][k] = sparse_B[1][j];
        Sum[2][k] = sparse_B[2][j];
        j++;
        k++;
    }
    size_Sum = k;
    cout << "Addition of Sparse A and B is:" << endl;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < size_Sum; j++)
        {
            cout << Sum[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Part (c) \n";
    int r1, c1, r2, c2;
    cout << "Enter Row and Column of Matrix X:" << endl;
    cin >> r1 >> c1;
    cout << "Enter Row and Column of Matrix Y:" << endl;
    cin >> r2 >> c2;
    if (c1 == r2)
    {
        int X[r1][c1], Y[r2][c2];
        int size_X = 0, size_Y = 0;
        cout << "Enter Matrix X elements:" << endl;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                cin >> X[i][j];
                if ((X[i][j]) != 0)
                {
                    size_X++;
                }
            }
        }
        int sparse_X[3][size_X];
        cout << "Enter Matrix Y elements:" << endl;
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cin >> Y[i][j];
                if ((Y[i][j]) != 0)
                {
                    size_Y++;
                }
            }
        }
        int sparse_Y[3][size_Y];
        cout << "Original Matrix X is:" << endl;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                cout << X[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Original Matrix Y is:" << endl;
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                cout << Y[i][j] << " ";
            }
            cout << endl;
        }
        k = 0;
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                if (X[i][j] != 0)
                {
                    sparse_X[0][k] = i;
                    sparse_X[1][k] = j;
                    sparse_X[2][k] = X[i][j];
                    k++;
                }
            }
        }
        cout << "Sparse of Matrix X is:" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < size_X; j++)
            {
                cout << sparse_X[i][j] << " ";
            }
            cout << endl;
        }
        k = 0;
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                if (Y[i][j] != 0)
                {
                    sparse_Y[0][k] = i;
                    sparse_Y[1][k] = j;
                    sparse_Y[2][k] = Y[i][j];
                    k++;
                }
            }
        }
        cout << "Sparse of Matrix Y is:" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < size_Y; j++)
            {
                cout << sparse_Y[i][j] << " ";
            }
            cout << endl;
        }
        int sparse_P[3][size_X * size_Y];
        int size_P = 0;

        for (int i = 0; i < size_X; i++)
        {
            for (int j = 0; j < size_Y; j++)
            {
                if (sparse_X[1][i] == sparse_Y[0][j])
                {
                    int row = sparse_X[0][i];
                    int col = sparse_Y[1][j];
                    int val = sparse_X[2][i] * sparse_Y[2][j];
                    bool found = false;
                    for (int z = 0; z < size_P; z++)
                    {
                        if (sparse_P[0][z] == row && sparse_P[1][z] == col)
                        {
                            sparse_P[2][z] += val;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        sparse_P[0][size_P] = row;
                        sparse_P[1][size_P] = col;
                        sparse_P[2][size_P] = val;
                        size_P++;
                    }
                }
            }
        }

        cout << "Sparse of Product is:" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < size_P; j++)
                cout << sparse_P[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "Multiplication Not Possible" << endl;
    }
    return 0;
}