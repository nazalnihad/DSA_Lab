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
        cout << "\nsize of the stack is : " << top;
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
    int size, choice, val;
    cout << "Enter the size of the stack: ";
    cin >> size;

    array_stack a(size);

    while (1)
    {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Get Size\n";
        cout << "4. Show Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            a.push(val);
            break;

        case 2:
            a.pop();
            break;

        case 3:
            a.Size();
            break;

        case 4:
            a.show();
            break;

        case 5:
            exit(0);

        default:
            cout << "Invalid choice. Please try again.";
        }
    }

    return 0;
}

// Enter the size of the stack: 5

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 1
// Enter value to push: 1

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 1
// Enter value to push: 2

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 1
// Enter value to push: 3

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 1
// Enter value to push: 4

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 1
// Enter value to push: 5

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 1
// Enter value to push: 2
// Stack is full

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 2
// 5 popped

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 3
// size of the array is : 4

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 2
// 4 popped

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 3
// size of the array is : 3

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 4
// 1
// 2
// 3

// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 5
