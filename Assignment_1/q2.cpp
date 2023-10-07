#include <iostream>
using namespace std;

int sum(int n)
{
    if (n < 1)
        return 0;

    return n % 10 + sum(n / 10);
}

int main()
{
    int total, n;
    cout << "Enter the number : ";
    cin >> n;
    total = sum(n);
    cout << "sum of digits of the number is " << total << "\n";
    return 0;
}
