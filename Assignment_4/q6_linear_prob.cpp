// Implement a hash table with linear probing using array with the following operations :
// INSERT(key), DELETE(key), SEARCH(key).

#include <iostream>
using namespace std;

class hash_table
{
    const static int tb_size = 10;
    int size;
    int table[tb_size];

public:
    hash_table()
    {
        size = 0;
        for (int i = 0; i < tb_size; i++)
        {
            table[i] = -1;
        }
    }

    int hash(int key)
    {
        return key % tb_size;
    }

    void INSERT(int key)
    {
        if (size >= tb_size)
        {
            cout << "\ntable full";
            return;
        }

        int pos = hash(key);
        while (table[pos] != -1)
        {
            pos = (pos + 1) % tb_size;
        }
        size++;

        table[pos] = key;
    }

    void DELETE(int key)
    {
        int pos = hash(key);

        while (table[pos] != -1)
        {
            if (table[pos] == key)
            {
                cout << "\nKey deleted ";
                table[pos] = -1;
                size--;
                return;
            }
            pos = (pos + 1) % tb_size;
        }
        cout << "\nkey not found";
    }

    void SEARCH(int key)
    {
        int pos = hash(key);

        while (table[pos] != -1)
        {
            if (table[pos] == key)
            {
                cout << "\nKey found at index " << pos;
                return;
            }
            pos = (pos + 1) % tb_size;
        }
        cout << "\nkey not found";
    }

    void SHOW()
    {

        for (int i = 0; i < tb_size; i++)
        {
            if (table[i] != -1)
            {
                cout << "\n"
                     << table[i];
            }
        }
    }
};

int main()
{
    hash_table h;
    h.INSERT(1);
    h.INSERT(3);
    h.INSERT(5);
    h.INSERT(6);
    h.INSERT(6);
    // h.INSERT(6);
    // h.INSERT(6);
    // h.INSERT(6);
    // h.INSERT(6);
    // h.INSERT(6);
    // h.INSERT(6);

    h.SHOW();

    h.SEARCH(3);
    h.DELETE(3);
    h.SHOW();

    return 0;
}