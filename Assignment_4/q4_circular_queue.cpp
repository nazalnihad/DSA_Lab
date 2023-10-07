#include <iostream>
using namespace std;

class circular_queue
{
    int front, rear, size, capacity;
    int *arr;

public:
    circular_queue(int n)
    {
        front = -1;
        rear = -1;
        size = 0;
        capacity = n;
        arr = new int[n];
    }

    void enqueue(int n)
    {
        if (front == -1 && rear == -1)
        {
            rear += 1;
            front += 1;
        }

        else if (size == capacity)
        {
            cout << "overflow\n";
            return;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = n;
        size++;
    }

    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "queue is empty." << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        size--;
    }

    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);

        cout << endl;
    }
};

int main()
{
    int n, choice, val;
    cout << "\nEnter the size of queue : ";
    cin >> n;
    circular_queue cq(n);

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            cq.enqueue(val);
            break;

        case 2:
            cq.dequeue();
            break;

        case 3:
            cq.display();
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

// Enter the size of queue : 5

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Display Queue
// 4. Exit
// Enter your choice: 1
// Enter value to enqueue: 1

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Display Queue
// 4. Exit
// Enter your choice: 1
// Enter value to enqueue: 2

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Display Queue
// 4. Exit
// Enter your choice: 1
// Enter value to enqueue: 3

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Display Queue
// 4. Exit
// Enter your choice: 1
// Enter value to enqueue: 4

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Display Queue
// 4. Exit
// Enter your choice: 1
// Enter value to enqueue: 5

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Display Queue
// 4. Exit
// Enter your choice: 1
// Enter value to enqueue: 6
// overflow

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Display Queue
// 4. Exit
// Enter your choice: 3
// 1 2 3 4 5

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Display Queue
// 4. Exit
// Enter your choice: 2

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Display Queue
// 4. Exit
// Enter your choice: 3
// 2 3 4 5

// Menu:
// 1. Enqueue
// 2. Dequeue
// 3. Display Queue
// 4. Exit
// Enter your choice: 4