// . Write a recursive function that, given a string s, prints the characters of s in reverse order

#include <iostream>
using namespace std;

void reverse(string word, int length)
{
    if (length < 1)
    {
        cout << word[0];
        return;
    }
    cout << word[length];
    reverse(word, length - 1);
}

int main()
{
    string word;
    int length;

    cout << "Enter the word to find reverse : ";
    cin >> word;
    length = word.length();

    reverse(word, length - 1);
    return 0;
}

// OUTPUT

// Enter the word to find reverse : babu
// ubab