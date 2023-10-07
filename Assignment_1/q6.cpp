
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
