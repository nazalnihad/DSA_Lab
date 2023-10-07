#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class linkedList
{
    node *head1 = NULL;
    node *head2 = NULL;
    int *arr;
    int size;

public:
    void getList(int n);
    void spliceList();
    void printList();
};

void linkedList::getList(int n)
{
    size = n;
    arr = new int[size];
    cout << "\nEnter the elements with space : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void linkedList::spliceList()
{
    node *temp1 = head1;
    node *temp2 = head2;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            if (head1 == NULL)
            {
                head1 = new node(arr[i]);
                temp1 = head1;
            }
            else
            {
                temp1->next = new node(arr[i]);
                temp1 = temp1->next;
            }
        }
        else
        {
            if (head2 == NULL)
            {
                head2 = new node(arr[i]);
                temp2 = head2;
            }
            else
            {
                temp2->next = new node(arr[i]);
                temp2 = temp2->next;
            }
        }
    }
}

void linkedList::printList()
{
    cout << "\nList 1: ";
    node *temp1 = head1;
    while (temp1 != NULL)
    {
        cout << temp1->data;
        if (temp1->next != NULL)
        {
            cout << " -> ";
        }
        else
        {
            cout << " -> NULL";
        }
        temp1 = temp1->next;
    }
    if (head1 == NULL)
    {
        cout << "NULL";
    }

    cout << "\nList 2: ";
    node *temp2 = head2;
    while (temp2 != NULL)
    {
        cout << temp2->data;
        if (temp2->next != NULL)
        {
            cout << " -> ";
        }
        else
        {
            cout << " -> NULL";
        }
        temp2 = temp2->next;
    }
    if (head2 == NULL)
    {
        cout << "NULL";
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in your main list : ";
    cin >> n;
    linkedList l;
    l.getList(n);
    l.spliceList();
    l.printList();
    return 0;
}
