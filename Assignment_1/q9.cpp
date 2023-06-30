// * Write a program to merge two sorted arrays of the same size to get a resultant array which
// is sorted in the reverse order. Analyse the time complexity of your algorithm

#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    // insetion sort in reverse order
    for (int i = 0; i < n - 1; i++)
    {
        int j = i;
        int key = arr[j + 1];

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// add elements to newly made array
int merge(int a[], int b[], int size)
{
    int new_size = size * 2;
    int merged[new_size];

    for (int i = 0; i < size; i++)
    {
        merged[i] = a[i];
        merged[size + i] = b[i];
    }

    // sort the newly made array in reverse and display
    sort(merged, new_size);
    for (int k = 0; k < new_size; k++)
    {
        cout << merged[k] << " ";
    }
}

void get_array(int arr[], int size)
{
    cout << "Enter array values : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
int main()
{

    int size;

    cout << "Enter the size of the arrays : ";
    cin >> size;
    int a[size], b[size];
    get_array(b, size);
    get_array(a, size);

    cout << "Merged and reverse sorted array is \n";
    merge(a, b, size);
    return 0;
}

// OUTPUT

// Enter the size of the arrays : 5
// Enter array values : 1 3 5 7 9
// Enter array values : 2 4 6 8 10
// Merged and reverse sorted array is
// 10 9 8 7 6 5 4 3 2 1