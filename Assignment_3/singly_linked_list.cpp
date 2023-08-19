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
    node *head;

public:
    linkedList() { head = NULL; }
    void insertNodes(int size);
    void printList();
    void searchNode(int key);
    void countDupes(int key);
    void deletDupe(int key);
    void insertAt(int key, int pos);
};

void linkedList::insertNodes(int size)
{
    int list[size];
    cout << "Enter the elements separated by spaces : ";
    for (int i = 0; i < size; i++)
    {
        cin >> list[i];
    }
    head = new node(list[0]);
    node *temp = head;
    for (int i = 1; i < size; i++)
    {
        temp->next = new node(list[i]);
        temp = temp->next;
    }
}

void linkedList::printList()
{
    node *temp = head;
    cout << "\n";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

void linkedList::searchNode(int key)
{
    int position = 1;
    node *temp = head;
    bool found = false;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (found)
    {
        cout << "\nKey " << key << " found at position " << position;
    }
    else
    {
        cout << "\nKEY NOT FOUND ";
    }
}

void linkedList::countDupes(int key)
{
    int dupeCount = 0;
    bool found = false;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            dupeCount++;
            found = true;
        }
        temp = temp->next;
    }

    if (found && dupeCount > 1)
    {
        cout << "\nkey " << key << " is duplicated " << dupeCount << " times";
    }
    else if (found && dupeCount == 1)
    {
        cout << "\nKey " << key << " is not repeated";
    }
    else
    {
        cout << "\nKEY NOT FOUND";
    }
}

void linkedList::deletDupe(int key)
{
    int flag = 0;
    while (head != NULL && head->data == key)
    {
        // node *temp = head;
        flag++;
        if (flag > 1)
        {
            head = head->next;
        }
        else
        {
            head = head->next;
        }
        // delete temp;
    }

    node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            // node *dupe = temp->next;
            flag++;
            if (flag > 1)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }

            // delete dupe;
        }
        else
        {
            temp = temp->next;
        }
    }
}

void linkedList::insertAt(int key, int pos)
{
    int position = 1;
    node *temp = head;
    if (pos == 1)
    {
        node *temp = head;
        head = new node(key);
        head->next = temp;
        return;
    }
    while (temp != NULL && position < pos - 1)
    {
        if (position == pos - 1)
        {
            node *previousNode = temp;
            node *nextNode = temp->next;
            previousNode->next = new node(key);
            previousNode->next->next = nextNode;
        }

        position++;
        temp = temp->next;
    }

    if (pos - 1 > position)
    {
        cout << "\nLIST IS TOO SMALL";
        return;
    }
}
int main()
{
    linkedList l;
    l.insertNodes(5);
    l.printList();
    // l.searchNode(3);
    // l.searchNode(10);
    l.countDupes(2);
    // l.countDupes(1);
    // l.countDupes(10);
    l.deletDupe(2);
    // l.insertAt(2, 5);
    l.printList();

    return 0;
}