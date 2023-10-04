#include <iostream>
using namespace std;

class array_stack
{
    int size, top;
    int *arr;

public:
    array_stack(int size)
    {
        this->size = size;
        top = 0;
        arr = new int[size];
    }
    bool isEmpty()
    {
        return top == 0;
    }
    void push(int val)
    {
        if (top == size)
        {
            cout << "\nStack is full";
            return;
        }
        else
        {
            arr[top] = val;
            top++;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "\nStack empty";
            return;
        }
        else
        {
            top--;
            cout << "\n"
                 << arr[top] << " popped";
        }
    }
    void Size()
    {
        cout << "\nsize of the array is : " << (top);
    }
    void show()
    {
        for (int i = 0; i < top; i++)
        {
            cout << "\n"
                 << arr[i];
        }
    }
};

int main()
{
    array_stack a(5);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(2);
    a.pop();
    a.Size();
    a.pop();
    a.Size();
    a.show();
}