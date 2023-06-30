// * Write a program to count the total number of duplicate elements in an unsorted character
// array in O(n) time complexity.

#include <iostream>
using namespace std;
int duplicates(char arr[], int size)
{
    int chars = 256;
    int count[chars] = {0};

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    int dupecount = 0;
    for (int i = 0; i < chars; i++)
    {
        if (count[i] > 1)
        {
            dupecount += (count[i] - 1);
        }
    }

    return dupecount;
}

int main()
{
    int size;
    cout << "Enter size of the array : ";
    cin >> size;

    char arr[size];
    cout << "Enter elements of the array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int dupecount = duplicates(arr, size);
    std::cout << "Total number of duplicate elements: " << dupecount;

    return 0;
}

// OUTPUT

// Enter size of the array : 5
// Enter elements of the array : a b d c d
// Total number of duplicate elements: 1