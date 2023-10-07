#include <iostream>
using namespace std;

void insertion_sort(float array[], int length)
{
    for (int i = 1; i < length; i++)
    {
        float key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] < key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void print_array(float arr[], int n)
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
    float arr[n];
    cout << "\nEnter elements in the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nBefore sorting : ";
    print_array(arr, n);

    cout << "\nAfter sorting : ";
    insertion_sort(arr, n);
    print_array(arr, n);

    return 0;
}
