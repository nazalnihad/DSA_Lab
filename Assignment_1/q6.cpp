// Write a menu driven program that repeatedly reads an option from the terminal to do the
// following array operations on array ARR:
// Option 1. Read integer n (<=100) , the size of array followed by n integer elements of
// ARR
// Option 2. Print the elements of array ARR
// Option 3. Read an integer elem to search in the array. Print FOUND/SORRY
// accordingly
// Option 4. Print the largest and smallest element of the array
// Option 5. Exit
// The program should be modular and should contain the following functions :
// main(), read_arr(int[] arr, int n), print_arr(int[] arr, int n), search_arr(int[] arr, int n,
// int elem), get_max(int[] arr, int n), get_min(int[] arr, int n)

#include <iostream>
using namespace std;

// read array
void read_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
}

// print array
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// search in array
void search_arr(int arr[], int n, int elem)
{
    if (arr[n] == elem)
    {
        cout << "FOUND\n";
        return;
    }
    else if (n == 0 && arr[0] != elem)
    {
        cout << "SORRY\n";
    }
    else
    {
        search_arr(arr, n - 1, elem);
    }
}

// get max in array
int get_max(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

// get min in array
int get_min(int arr[], int n)
{
    int smallest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    return smallest;
}

int main()
{
    int size, elem, max, min, choice;
    cout << "1 - to start\n any other key to quit \n : ";
    cin >> choice;
    while (choice == 1)
    {
        cout << "\nEnter the size of the array : ";
        cin >> size;
        int arr[size];
        int option;
        do
        {
            cout << "\n1 - to read array \n2 - print array \n3 - search in array \n4 - to get min and max \n5 - to exit or start new array \n : ";
            cin >> option;

            switch (option)
            {
            case 1:
                read_arr(arr, size);
                break;

            case 2:
                cout << "\n";
                print_arr(arr, size);
                break;

            case 3:
                cout << "\nEnter the element you want to search : ";
                cin >> elem;
                search_arr(arr, size - 1, elem);
                break;

            case 4:
                min = get_min(arr, size);
                max = get_max(arr, size);
                cout << "\nMax = " << max << "\nMin = " << min << "\n";
                break;

            case 5:
                cout << "1 - to start with another array \nany other key to exit \n : ";
                cin >> choice;
                break;

            default:
                cout << "\nEnter a valid option ";
                break;
            }
        } while (option != 5);
    }
    return 0;
}

// OUTPUT

// 1 - to start
//  any other key to quit
//  : 1

// Enter the size of the array : 5

// 1 - to read array
// 2 - print array
// 3 - search in array
// 4 - to get min and max
// 5 - to exit or start new array
//  : 1
// Enter element 1 : 1
// Enter element 2 : 2
// Enter element 3 : 3
// Enter element 4 : 4
// Enter element 5 : 5

// 1 - to read array
// 2 - print array
// 3 - search in array
// 4 - to get min and max
// 5 - to exit or start new array
//  : 2

// 1 2 3 4 5
// 1 - to read array
// 2 - print array
// 3 - search in array
// 4 - to get min and max
// 5 - to exit or start new array
//  : 3

// Enter the element you want to search : 3
// FOUND

// 1 - to read array
// 2 - print array
// 3 - search in array
// 4 - to get min and max
// 5 - to exit or start new array
//  : 4

// Max = 5
// Min = 1

// 1 - to read array
// 2 - print array
// 3 - search in array
// 4 - to get min and max
// 5 - to exit or start new array
//  : 5
// 1 - to start with another array
// any other key to exit
//  : 2