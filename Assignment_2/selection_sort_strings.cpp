#include <iostream>
using namespace std;

void selection_sort(string arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            string temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}
void print_array(string arr[], int n)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int n;
    cout << "Enter no of elements : ";
    cin >> n;
    string arr[n];
    cout << "\nEnter elements in the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nBefore sorting : ";
    print_array(arr, n);

    cout << "\nAfter sorting : ";
    selection_sort(arr, n);
    print_array(arr, n);

    return 0;
}
// Input output
// Enter no of elements : 9

// Enter elements in the array : one picture is worth more than ten thousand words

// Before sorting : 
// one picture is worth more than ten thousand words 

// After sorting :
// is more one picture ten than thousand words worth 