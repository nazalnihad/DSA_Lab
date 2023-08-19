#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class linkedList
{
    node *head = NULL;
    node *tail = NULL;
    int *arr, size;

public:
    void getList(int n);
    void singleList();
    void doubleList();
    void disp_h_t();
    void disp_t_h();
};

void linkedList::getList(int n)
{
    size = n;
    arr = new int[size];
    cout << "Enter the elements in the list : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void linkedList::singleList()
{
    head = new node(arr[0]);
    node *temp = head;
    for (int i = 1; i < size; i++)
    {
        temp->next = new node(arr[i]);
        temp = temp->next;
    }
}

void linkedList::doubleList()
{

    node *last = NULL;
    node *temp = head;

    while (temp != NULL)
    {
        temp->prev = last;
        last = temp;
        tail = last;
        temp = temp->next;
    }
    tail->next = NULL;
    head->prev = NULL;
}

// head to tail display
void linkedList::disp_h_t()
{
    node *temp = head;
    cout << "\nHead to tail display ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

// tail to head display
void linkedList::disp_t_h()
{
    node *temp = tail;
    cout << "\nTail to head display: ";
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->prev != NULL)
        {
            cout << " -> ";
        }
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    linkedList l;
    l.getList(5);
    l.singleList();
    l.doubleList();
    l.disp_h_t();
    l.disp_t_h();

    return 0;
}