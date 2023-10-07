#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node()
    {
        data = 0;
        next = nullptr;
    }

    node(int n)
    {
        data = n;
        next = nullptr;
    }
};

class linked_stack
{
    node *head = nullptr;
    int size = 0;

public:
    void push(int val)
    {
        if (head == nullptr)
        {
            head = new node(val);
        }
        else
        {
            node *temp = head;
            head = new node(val);
            head->next = temp;
        }
        size++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "\nStack empty";
            return;
        }

        cout << "\npopped " << head->data;
        node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void Size()
    {
        cout << "\nsize is " << size;
    }

    void show()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << "\n"
                 << temp->data;
            temp = temp->next;
        }
    }
};

int main()
{
    linked_stack a;
    int choice, val;

    while (true)
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
// Enter your choice: 4

// 3
// 2
// 1
// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 2

// popped 3
// Menu:
// 1. Push
// 2. Pop
// 3. Get Size
// 4. Show Stack
// 5. Exit
// Enter your choice: 5