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
            cout << "\nTable full";
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
                cout << "\nKey " << key << " deleted";
                size--;
                table[pos] = -1;
                return;
            }
            pos = (pos + step) % tb_size;
        }
        cout << "\nKey not found";
    }

    void SEARCH(int key)
    {
        int pos = hash1(key);
        int step = hash2(key);
        while (table[pos] != -1)
        {
            if (table[pos] == key)
            {
                cout << "\nKey " << key << " found at index " << pos;
                return;
            }
            pos = (pos + step) % tb_size;
        }
        cout << "\nKey not found";
    }

    void SHOW()
    {
        for (int i = 0; i < tb_size; i++)
        {
            if (table[i] != -1)
            {
                cout << "\n"
                     << i << ": " << table[i];
            }
        }
    }
};

int main()
{
    hash_table h;
    int choice, key;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            h.INSERT(key);
            break;

        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            h.DELETE(key);
            break;

        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            h.SEARCH(key);
            break;

        case 4:
            h.SHOW();
            break;

        case 5:
            exit(0);

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 1
// Enter key to insert: 1

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 1
// Enter key to insert: 3

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 1
// Enter key to insert: 5

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 1
// Enter key to insert: 6

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 4

// 1: 1
// 3: 3
// 5: 5
// 6: 6
// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 3
// Enter key to search: 3

// Key 3 found at index 3
// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 2
// Enter key to delete: 3

// Key 3 deleted
// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 4

// 1: 1
// 5: 5
// 6: 6
// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 5