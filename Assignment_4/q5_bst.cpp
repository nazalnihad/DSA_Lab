#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int n)
    {
        data = n;
        left = nullptr;
        right = nullptr;
    }
};

node *insert(node *pos, int key)
{
    if (pos == nullptr)
    {
        pos = new node(key);
    }
    else
    {
        if (pos->data > key)
        {
            pos->left = insert(pos->left, key);
        }
        else
        {
            pos->right = insert(pos->right, key);
        }
    }
    return pos;
}

node *min(node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

node *Delete(node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    else
    {
        if (key < root->data)
        {
            root->left = Delete(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = Delete(root->right, key);
        }
        else
        {
            if (root->left == nullptr)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                node *temp = min(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        return root;
    }
}

bool search(node *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }
    else
    {
        if (key == root->data)
        {
            return true;
        }
        else if (key < root->data)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }
}

void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->right);
    postorder(root->left);
    cout << root->data << " ";
}

int main()
{
    node *root = nullptr;
    int choice, val;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Preorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = Delete(root, val);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            if (search(root, val))
            {
                cout << "Found" << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
            break;

        case 4:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;

        case 6:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 7:
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
// 4. Inorder Traversal
// 5. Postorder Traversal
// 6. Preorder Traversal
// 7. Exit
// Enter your choice: 1
// Enter value to insert: 1

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Inorder Traversal
// 5. Postorder Traversal
// 6. Preorder Traversal
// 7. Exit
// Enter your choice: 1
// Enter value to insert: 2

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Inorder Traversal
// 5. Postorder Traversal
// 6. Preorder Traversal
// 7. Exit
// Enter your choice: 1
// Enter value to insert: 3

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Inorder Traversal
// 5. Postorder Traversal
// 6. Preorder Traversal
// 7. Exit
// Enter your choice: 1
// Enter value to insert: 4

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Inorder Traversal
// 5. Postorder Traversal
// 6. Preorder Traversal
// 7. Exit
// Enter your choice: 3
// Enter value to search: 1
// Found

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Inorder Traversal
// 5. Postorder Traversal
// 6. Preorder Traversal
// 7. Exit
// Enter your choice: 4
// Inorder Traversal: 1 2 3 4

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Inorder Traversal
// 5. Postorder Traversal
// 6. Preorder Traversal
// 7. Exit
// Enter your choice: 2
// Enter value to delete: 2

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Inorder Traversal
// 5. Postorder Traversal
// 6. Preorder Traversal
// 7. Exit
// Enter your choice: 5
// Postorder Traversal: 4 3 1

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Inorder Traversal
// 5. Postorder Traversal
// 6. Preorder Traversal
// 7. Exit
// Enter your choice: 6
// Preorder Traversal: 1 3 4

// Menu:
// 1. Insert
// 2. Delete
// 3. Search
// 4. Inorder Traversal
// 5. Postorder Traversal
// 6. Preorder Traversal
// 7. Exit
// Enter your choice: 7