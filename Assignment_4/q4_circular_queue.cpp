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
            cout << "\nqueue is empty";
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
    circular_queue cq(5);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(6);
    cq.enqueue(7);

    cq.display();

    return 0;
}
