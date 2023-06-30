// Write a recursive function that checks whether a string is a palindrome (a palindrome is a
// string that's the same when reads forwards and backwards.)
#include <iostream>
using namespace std;

bool palindrome(string word, int end, int start = 0)
{
    if (word[start] == word[end])
    {
        return true;
    }
    else
    {
        return false;
    }
    palindrome(word, start + 1, end - 1);
}

int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;

    if (palindrome(s, s.length() - 1))
    {
        cout << "the word is a palindrome";
    }
    else
    {
        cout << "the word is not a palindrome";
    }
    return 0;
}

// OUTPUT

// Enter the string : malayalam
// the word is a palindrome