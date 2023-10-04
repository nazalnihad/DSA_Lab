// Implement a hash table with linear probing using array with the following operations :
// INSERT(key), DELETE(key), SEARCH(key).

#include <iostream>
using namespace std;

class hash_table
{
    const static int tb_size = 10;
    int table[tb_size];
    int size;

public:
    hash_table()
    {
        size = 0;
        for (int i = 0; i < tb_size; i++)
        {
            table[i] = -1;
        }
    }

    int hash1(int key)
    {
        return key % tb_size;
    }
    int hash2(int key)
    {
        return 7 - (key % 7);
    }

    void INSERT(int key)
    {
        if (size >= tb_size)
        {
            cout << "\ntable full";
            return;
        }

        int pos = hash1(key);
        int step = hash2(key);
        while (table[pos] != -1)
        {
            pos = (pos + step) % tb_size;
        }
        size++;
        table[pos] = key;
    }

    void DELETE(int key)
    {
        int pos = hash1(key);
        int step = hash2(key);
        while (table[pos] != -1)
        {
            if (table[pos] == key)
            {
                cout << "\nKey deleted ";
                size--;
                table[pos] = -1;
                return;
            }
            pos = (pos + step) % tb_size;
        }
        cout << "\nkey not found";
    }

    void SEARCH(int key)
    {
        int pos = hash1(key);
        int step = hash2(key);
        while (table[pos] != -1)
        {
            if (table[pos] == key)
            {
                cout << "\nKey found at index " << pos;
                return;
            }
            pos = (pos + step) % tb_size;
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
    h.INSERT(6);
    h.INSERT(6);
    h.INSERT(6);
    h.INSERT(6);
    h.INSERT(6);
    h.INSERT(6);

    h.SHOW();

    h.SEARCH(3);
    h.DELETE(3);
    h.SHOW();

    return 0;
}