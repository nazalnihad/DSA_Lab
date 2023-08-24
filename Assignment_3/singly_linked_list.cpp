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
        if (temp->next == NULL)
        {
            cout << "NULL";
        }
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
            cout << "\nKey " << key << " found at position " << position;
        }
        temp = temp->next;
        position++;
    }

    if (!found)
    {
        cout << "\nKEY NOT FOUND";
    }
}

void linkedList::countDupes(int key)
{
    int dupeCount = 0;
    node *temp = head;
    bool found = false;

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
        cout << "\nkey " << key << " is duplicated " << dupeCount - 1 << " times";
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
    node *temp = head;

    bool found = false; // Initialize the found flag

    while (temp != NULL && temp->data == key)
    {
        flag++;
        if (flag > 1)
        {
            head = head->next;
        }

        temp = temp->next;
        found = true; // Mark as found

        // delete temp;
    }

    temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            // node *dupe = temp->next;
            flag++;
            if (flag > 1)
            {
                temp->next = temp->next->next;
                found = true;
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

    if (!found)
    {
        cout << "\nKEY NOT FOUND";
        return;
    }

    if (flag == 1)
    {
        cout << "\nKey " << key << " is not repeated";
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
        position++;
        return;
    }
    while (temp != NULL && position <= pos)
    {
        if (position == pos)
        {
            node *previousNode = temp;
            node *nextNode = temp->next;
            previousNode->next = new node(key);
            previousNode->next->next = nextNode;
        }

        position++;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "\nLIST IS TOO SMALL";
        return;
    }
}
int main()
{
    linkedList l;
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    l.insertNodes(n);

    char choice;
    while (true)
    {
        cout << "\n\nMenu:\n";
        cout << "s key - Search for an element\n";
        cout << "c key - Count duplicates\n";
        cout << "r key - Remove duplicates\n";
        cout << "i key pos - Insert element at position\n";
        cout << "d - to display the list\n";
        cout << "e - Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        if (choice == 'e')
        {
            break;
        }

        int key, pos;
        switch (choice)
        {
        case 's':
            cout << "Enter the key to search: ";
            cin >> key;
            l.searchNode(key);
            break;
        case 'c':
            cout << "Enter the key to count duplicates: ";
            cin >> key;
            l.countDupes(key);
            break;
        case 'r':
            cout << "Enter the key to remove duplicates: ";
            cin >> key;
            l.deletDupe(key);
            l.printList();
            break;
        case 'i':
            cout << "Enter the key to insert: ";
            cin >> key;
            cout << "Enter the position to insert: ";
            cin >> pos;
            l.insertAt(key, pos);
            break;
        case 'd':
            l.printList();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}

// INPUT OUTPUT
// Enter the number of elements in the list: 5
// Enter the elements separated by spaces : 1 2 2 3 4

// Menu:
// s key - Search for an element
// c key - Count duplicates
// r key - Remove duplicates
// i key pos - Insert element at position
// d - to display the list
// e - Exit
// Enter your choice: s
// Enter the key to search: 2

// Key 2 found at position 2
// Key 2 found at position 3

// Menu:
// s key - Search for an element
// c key - Count duplicates
// r key - Remove duplicates
// i key pos - Insert element at position
// d - to display the list
// e - Exit
// Enter your choice: c
// Enter the key to count duplicates: 2

// key 2 is duplicated 1 times

// Menu:
// s key - Search for an element
// c key - Count duplicates
// r key - Remove duplicates
// i key pos - Insert element at position
// d - to display the list
// e - Exit
// Enter your choice: r
// Enter the key to remove duplicates: 2

// 1 -> 2 -> 3 -> 4 -> NULL

// Menu:
// s key - Search for an element
// c key - Count duplicates
// r key - Remove duplicates
// i key pos - Insert element at position
// d - to display the list
// e - Exit
// Enter your choice: i
// Enter the key to insert: 2
// Enter the position to insert: 1

// Menu:
// s key - Search for an element
// c key - Count duplicates
// r key - Remove duplicates
// i key pos - Insert element at position
// d - to display the list
// e - Exit
// Enter your choice: d

// 2 -> 1 -> 2 -> 3 -> 4 -> NULL

// Menu:
// s key - Search for an element
// c key - Count duplicates
// r key - Remove duplicates
// i key pos - Insert element at position
// d - to display the list
// e - Exit
// Enter your choice: e