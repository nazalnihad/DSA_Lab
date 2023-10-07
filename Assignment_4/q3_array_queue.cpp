#include <iostream>
using namespace std;

class array_queue
{
    int size, front, rear;
    int *arr;

public:
    array_queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    void enqueue(int n)
    {
        if (rear == size - 1)
        {
            cout << "\nQueue is full";
            return;
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = n;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "\nqueue is empty";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }

    void SIZE()
    {
        cout << "\nsize is " << rear - front + 1;
    }

    void display()
    {
        cout << "\n";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    int n;
    cout << "\nEnter the size : ";
    cin >> n;
    array_queue q(n);
    int choice, val;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Get Size\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.SIZE();
            break;

        case 4:
            q.display();
            break;

        case 5:
            exit(0);

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

// Enter the size : 5

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Get Size
// 4. Display Queue
// 5. Exit
// Enter your choice: 1
// Enter value to enqueue: 1

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Get Size
// 4. Display Queue
// 5. Exit
// Enter your choice: 1
// Enter value to enqueue: 2

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Get Size
// 4. Display Queue
// 5. Exit
// Enter your choice: 1
// Enter value to enqueue: 3

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Get Size
// 4. Display Queue
// 5. Exit
// Enter your choice: 1
// Enter value to enqueue: 4

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Get Size
// 4. Display Queue
// 5. Exit
// Enter your choice: 1
// Enter value to enqueue: 5

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Get Size
// 4. Display Queue
// 5. Exit
// Enter your choice: 1
// Enter value to enqueue: 6

// Queue is full
// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Get Size
// 4. Display Queue
// 5. Exit
// Enter your choice: 4

// 1 2 3 4 5
// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Get Size
// 4. Display Queue
// 5. Exit
// Enter your choice: 2

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Get Size
// 4. Display Queue
// 5. Exit
// Enter your choice: 4

// 2 3 4 5
// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Get Size
// 4. Display Queue
// 5. Exit
// Enter your choice: 3

// size is 4
// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Get Size
// 4. Display Queue
// 5. Exit
// Enter your choice: 5