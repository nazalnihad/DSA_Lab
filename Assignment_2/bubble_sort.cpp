#include <iostream>
using namespace std;

void bubbleSort(float arr[], int n)
{
    bool swap;

    for (int i = 0; i < n - 1; i++)
    {
        swap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                float temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swap = true;
            }
        }
        if (!swap)
            break;
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
    bubbleSort(arr, n);
    print_array(arr, n);

    return 0;
}
