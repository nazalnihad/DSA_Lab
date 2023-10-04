#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    // node
    node(int n)
    {
        data = n;
        next = nullptr;
    }
};

class hash_table
{
    const static int tb_size = 10;
    node *table[tb_size];

public:
    hash_table()
    {
        for (int i = 0; i < tb_size; i++)
        {
            table[i] = nullptr;
        }
    }

    int hash(int key)
    {
        return key % tb_size;
    }

    void INSERT(int key)
    {
        int pos = hash(key);
        node *new_node = new node(key);

        if (table[pos] == nullptr)
        {
            table[pos] = new_node;
        }
        else
        {
            node *temp = table[pos];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    void DELETE(int key)
    {
        int pos = hash(key);
        // node *new_node = new node(n);
        node *prev = nullptr;

        node *temp = table[pos];
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                if (prev == nullptr)
                {
                    table[pos] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "\nkey not found";
    }

    void SEARCH(int key)
    {
        int pos = hash(key);
        node *temp = table[pos];

        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout << "\nFound key";
                return;
            }
            temp = temp->next;
        }
        cout << "\nkey not found";
    }

    void SHOW()
    {
        for (int i = 0; i < tb_size; i++)
        {
            cout << "Index " << i << ": ";
            node *temp = table[i];
            while (temp != nullptr)
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

int main()
{
    hash_table ht;

    ht.INSERT(1);
    ht.INSERT(11);
    ht.INSERT(21);
    ht.INSERT(3);
    ht.INSERT(13);
    ht.INSERT(23);

    cout << "Hash Table after insertions:" << endl;
    ht.SHOW();

    ht.SEARCH(11);
    ht.SEARCH(5);

    ht.DELETE(11);
    ht.DELETE(5); // Attempting to delete a key that doesn't exist

    cout << "\nHash Table after deletions:"
         << "\n";
    ht.SHOW();

    return 0;
}