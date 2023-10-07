#include <iostream>
using namespace std;

void binary(int n)
{

    if (n != 0)
    {
        binary(n / 2);
        cout << n % 2;
    }
    else
    {
        cout << 0;
        return;
    }
}
int main()
{
    int num;
    cout << "Enter number to convert to binary : ";
    cin >> num;
    cout << "The converted binary is : ";
    binary(num);
    return 0;
}
