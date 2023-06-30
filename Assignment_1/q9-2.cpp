// * Write a program to merge two sorted arrays of the same size to get a resultant array which
// is sorted in the reverse order. Analyse the time complexity of your algorithm

#include <iostream>
using namespace std;

void reverseMerge(int a[], int b[], int size)
{
    int merged[size * 2];
    int i = 0;
    int j = 0;
    int new_size = size * 2 - 1;

    // compare first elements of each array and change values accordingly
    while (i < size && j < size)
    {
        if (a[i] <= b[j])
        {
            merged[new_size] = a[i];
            i++;
        }
        else
        {
            merged[new_size] = b[j];
            j++;
        }
        new_size--;
    }

    // add rest of element which was left after comparison above
    while (i < size)
    {
        merged[new_size] = a[i];
        i++;
        new_size--;
    }

    while (j < size)
    {
        merged[new_size] = b[j];
        j++;
        new_size--;
    }

    for (int f = 0; f < size * 2; f++)
    {
        cout << merged[f] << " ";
    }
}

int main()
{
    int size;
    cout << "Enter size of the arrays : ";
    cin >> size;

    int arr1[size], arr2[size];

    cout << "\nEnter elements of array 1 in sorted order : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr1[i];
    }
    cout << "\nEnter elements of array 2 in sorted order : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr2[i];
    }

    cout << "Merged and reverse sorted array is \n";
    reverseMerge(arr1, arr2, size);

    return 0;
}

// OUTPUT

// Enter size of the arrays : 4

// Enter elements of array 1 in sorted order : 1 3 5 7

// Enter elements of array 2 in sorted order : 2 4 6 8
// Merged and reverse sorted array is
// 8 7 6 5 4 3 2 1