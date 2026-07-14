#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* createNode(int value)
{
    BSTNode* newNode = new BSTNode;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BSTNode* insert(BSTNode* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(BSTNode* current)
{
    if (current != NULL)
    {
        inorder(current->left);
        cout << current->data << " ";
        inorder(current->right);
    }
}

void preorder(BSTNode* current)
{
    if (current != NULL)
    {
        cout << current->data << " ";
        preorder(current->left);
        preorder(current->right);
    }
}

void postorder(BSTNode* current)
{
    if (current != NULL)
    {
        postorder(current->left);
        postorder(current->right);
        cout << current->data << " ";
    }
}

BSTNode* search(BSTNode* root, int value)
{
    if (root == NULL)
        return NULL;

    if (root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// ✅ Helper: find minimum node in a subtree (inorder successor)
BSTNode* findMin(BSTNode* root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

// ✅ Delete function
BSTNode* deleteNode(BSTNode* root, int value)
{
    if (root == NULL)
        return root;

    // Step 1: value ko dhoondho
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Step 2: Node mil gaya — ab 3 cases

        // Case 1: leaf node (no child)
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // Case 2: one child (right only)
        else if (root->left == NULL)
        {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: one child (left only)
        else if (root->right == NULL)
        {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: two children
        else
        {
            BSTNode* temp = findMin(root->right);   // inorder successor
            root->data = temp->data;               // copy successor value
            root->right = deleteNode(root->right, temp->data); // delete successor
        }
    }

    return root;
}

int main()
{
    BSTNode* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    // Search
    int key;
    cout << "\n\nEnter value to search: ";
    cin >> key;

    BSTNode* result = search(root, key);

    if (result != NULL)
        cout << "Search: " << key << " Found";
    else
        cout << "Search: " << key << " Not Found";

    // ✅ Delete
    int delVal;
    cout << "\n\nEnter value to delete: ";
    cin >> delVal;

    root = deleteNode(root, delVal);

    cout << "\nInorder after deletion: ";
    inorder(root);

    cout << endl;
    return 0;
}