// Write a recursive implementation of the factorial function. Recall that n! = 1 × 2 × ... × n,
// with the special case that 0! = 1.

#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n < 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    int fact, n;
    cout << "Enter the number to find factorial : ";
    cin >> n;
    fact = factorial(n);
    cout << "the factorial of " << n << " is " << fact;
    return 0;
}

// OUTPUT

// Enter the number to find factorial : 5
// the factorial of 5 is 120