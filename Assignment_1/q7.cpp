// * Write a program to find the second largest element of a given integer array. Can you
// modify it to find the k-th largest element?

#include <iostream>
using namespace std;

void second_largest(int arr[], int n)
{
    // without sorting
    int largest, second_largest;
    largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] < largest)
        {
            second_largest = arr[i];
        }
    }
    cout << "second largest = " << second_largest << "\n";
}
void kth_largest(int arr[], int n, int k)
{
    // insertion sort
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int key = arr[j + 1];

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "The " << k << "th largest number of the array is : " << arr[n - k] << "\n";
}

int main()
{
    int size, choice, option, k;

    cout << "\n1 - to start \nany other key to quit \n : ";
    cin >> choice;

    while (choice == 1)
    {
        cout << "Enter the size of the array : ";
        cin >> size;
        int arr[size];
        cout << "Enter the array elements : ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        do
        {
            cout << "\n1 - to find the 2nd largest array \n2 - to find the Kth largest element \n3 - to quit \n : ";
            cin >> option;

            switch (option)
            {
            case 1:
                second_largest(arr, size);
                break;

            case 2:
                cout << "Enter k , for kth largest : ";
                cin >> k;
                kth_largest(arr, size, k);
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
}

// OUTPUT

// 1 - to start
// any other key to quit
//  : 1
// Enter the size of the array : 5
// Enter the array elements : 1 2 3 4 5

// 1 - to find the 2nd largest array
// 2 - to find the Kth largest element
// 3 - to quit
//  : 1
// second largest = 4

// 1 - to find the 2nd largest array
// 2 - to find the Kth largest element
// 3 - to quit
//  : 2
// Enter k , for kth largest : 3
// The 3th largest number of the array is : 3

// 1 - to find the 2nd largest array
// 2 - to find the Kth largest element
// 3 - to quit
//  : 2
// Enter k , for kth largest : 4
// The 4th largest number of the array is : 2

// 1 - to find the 2nd largest array
// 2 - to find the Kth largest element
// 3 - to quit
//  : 3

// 1 - to continue with another array
// any other key to quit
//  : 2