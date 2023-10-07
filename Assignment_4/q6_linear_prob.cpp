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
            cout << "\nTable full";
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
                cout << "\nKey " << key << " deleted";
                table[pos] = -1;
                size--;
                return;
            }
            pos = (pos + 1) % tb_size;
        }
        cout << "\nKey not found";
    }

    void SEARCH(int key)
    {
        int pos = hash(key);

        while (table[pos] != -1)
        {
            if (table[pos] == key)
            {
                cout << "\nKey " << key << " found at index " << pos;
                return;
            }
            pos = (pos + 1) % tb_size;
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
// Enter key to insert: 5

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 1
// Enter key to insert: 15

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 1
// Enter key to insert: 25

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 3
// Enter key to search: 15
// Key 15 found at index 5

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 2
// Enter key to delete: 15
// Key 15 deleted

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 4
// 0: 5
// 2: 25

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Display Table
// 5. Exit
// Enter your choice: 5
