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
        cout << "\npopped " << head->data;
        head = head->next;
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
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    // a.push(2);
    a.Size();
    a.pop();
    a.Size();
    a.pop();
    a.Size();
    a.show();
}