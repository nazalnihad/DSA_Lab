
#include <iostream>
using namespace std;

class matrix
{
    int row, col;
    int **p;

public:
    int get_matrix(int, int);
    void print_matrix();
    int row_col_sum();
    void largest_row_col(int arr[], int n);
};

int matrix::get_matrix(int x, int y)
{
    row = x;
    col = y;
    p = new int *[row];
    for (int i = 0; i < row; i++)
    {
        p[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        cout << "Row " << i + 1 << "\n";
        for (int j = 0; j < col; j++)
        {
            cout << "Enter value at [" << i + 1 << "][" << j + 1 << "] : ";
            cin >> p[i][j];
        }
    }
}

void matrix::print_matrix()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }
}

// find the index+1(i.e number) of largest row or col sum according to input
void matrix::largest_row_col(int arr[], int n)
{
    int largest = arr[0];
    int index;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            index = i;
        }
    }
    cout << " is " << largest << " at number " << index + 1 << "\n";
}

int matrix::row_col_sum()
{
    int row_sum[row] = {0};
    int col_sum[col] = {0};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // for summation of row and col respectively
            row_sum[i] += p[i][j];
            col_sum[i] += p[j][i];
        }
    }

    for (int k = 0; k < row; k++)
    {
        cout << "sum of row " << k + 1 << " = " << row_sum[k] << "\n";
    }

    cout << "\nlargest row value ";
    largest_row_col(row_sum, row);
    cout << "\n";

    for (int k = 0; k < col; k++)
    {
        cout << "sum of col " << k + 1 << " = " << col_sum[k] << "\n";
    }

    cout << "\nlargest col value";
    largest_row_col(col_sum, col);
    cout << "\n";
}

int main()
{
    int row, col, choice, option;

    cout << "\n1 - to start \nany other key to quit \n : ";
    cin >> choice;

    while (choice == 1)
    {
        matrix a;
        cout << "Enter the no of rows : ";
        cin >> row;
        cout << "Enter no of cols : ";
        cin >> col;
        a.get_matrix(row, col);

        do
        {
            cout << "\n1 - to print the matrix \n2 - to find the largest row and col sum \n3 - to quit \n : ";
            cin >> option;

            switch (option)
            {
            case 1:
                a.print_matrix();
                break;

            case 2:
                a.row_col_sum();
                break;

            case 3:
                cout << "\n1 - to continue with another array \nany other key to quit \n : ";
                cin >> choice;
                break;

            default:
                cout << "\nPls choose a valid option ";
            }
        } while (option != 3);
    }
    return 0;
}
