
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
