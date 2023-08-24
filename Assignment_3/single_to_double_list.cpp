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
        temp = temp->next;
    }
    tail = last;
    tail->next = NULL;
    head->prev = NULL;
}

void linkedList::disp_h_t()
{
    node *temp = head;
    cout << "\nHead to tail display ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

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
    cout << "->NULL\n";
}

int main()
{
    linkedList l;
    int n;
    cout << "Enter size of list : ";
    cin >> n;
    l.getList(n);
    l.singleList();
    l.doubleList();

    bool exitMenu = false;
    while (!exitMenu)
    {
        cout << "\nMenu:\n";
        cout << "1 - Display list from head to tail\n";
        cout << "2 - Display list from tail to head\n";
        cout << "3 - Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            l.disp_h_t();
            break;
        case 2:
            l.disp_t_h();
            break;
        case 3:
            exitMenu = true;
            break;
        default:
            cout << "try again.\n";
            break;
        }
    }

    return 0;
}

// INPUT OUTPUT
// Enter size of list : 9
// Enter the elements in the list : 6 4 10 13 1 7 88 10 5

// Menu:
// 1 - Display list from head to tail
// 2 - Display list from tail to head
// 3 - Exit
// Enter your choice: 1

// Head to tail display 6 -> 4 -> 10 -> 13 -> 1 -> 7 -> 88 -> 10 -> 5 -> NULL
// Menu:
// 1 - Display list from head to tail
// 2 - Display list from tail to head
// 3 - Exit
// Enter your choice: 2

// Tail to head display: 5 -> 10 -> 88 -> 7 -> 1 -> 13 -> 10 -> 4 -> 6->NULL

// Menu:
// 1 - Display list from head to tail
// 2 - Display list from tail to head
// 3 - Exit
// Enter your choice: 3