#include <iostream>
using namespace std;

void sort(float array[], int start, int end, int mid)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;
    float left[leftSize];
    float right[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        left[i] = array[start + i];
    }
    for (int j = 0; j < rightSize; j++)
    {
        right[j] = array[mid + 1 + j];
    }

    int l = 0, r = 0, k = start;

    while (leftSize > l && rightSize > r)
    {
        if (left[l] < right[r])
        {
            array[k] = left[l];
            l++;
        }
        else
        {
            array[k] = right[r];
            r++;
        }
        k++;
    }

    while (l < leftSize)
    {
        array[k] = left[l];
        k++;
        l++;
    }
    while (r < rightSize)
    {
        array[k] = right[r];
        k++;
        r++;
    }
}

void merge_sort(float array[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        sort(array, start, end, mid);
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
    merge_sort(arr, 0, n);
    print_array(arr, n);

    return 0;
}

// Input output
// Enter no of elements : 8

// Enter elements in the array : 623.43 82.412 534.612 137.6 -733.216 28.16 363.532 8.34423

// Before sorting :
// 623.43 82.412 534.612 137.6 -733.216 28.16 363.532 8.34423

// After sorting :
// -733.216 5.88597e-039 8.34423 28.16 82.412 137.6 363.532 534.612