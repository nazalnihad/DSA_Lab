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
    array_queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    // q.enqueue(5);
    // q.enqueue(5);
    // q.enqueue(5);

    // q.SIZE();
    // q.dequeue();
    // q.SIZE();

    // q.dequeue();
    // q.SIZE();

    // cout << "Queue: ";
    q.display();

    return 0;
}