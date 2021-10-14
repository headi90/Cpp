#include <iostream>

struct Node {
    int value_;
    Node* left = nullptr;
    Node* right = nullptr;
};

Node* newNode(int data)
{
    Node* node = new Node();
    node->value_ = data;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

void printTree(Node* root)
{
    if (root == nullptr)
        return;
    std::cout << root->value_ << "   ";
    printTree(root->left);
    printTree(root->right);
}

int countMaxDepth(Node* root)
{
    if (root == nullptr)
        return 0;

    int leftDepth = countMaxDepth(root->left);
    int rightDepth = countMaxDepth(root->right);

    return std::max(leftDepth + 1, rightDepth + 1);
}

void deleteTree(Node** root)
{
    if (*root == nullptr)
        return;

    deleteTree(&(*root)->left);
    deleteTree(&(*root)->right);

    std::cout << "Deleting: " << (*root)->value_ << '\n';
    delete *root;
    *root = nullptr;
}

int main()
{
    /*
                1
            /       \
            2       3
        /      \
      4         5
    /
   6
 /
7 

    */
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(7);

    std::cout << "printTree" << '\n';
    printTree(root);
    std::cout << "deleteTree" << '\n';
    std::cout << "MaxDepth: " << countMaxDepth(root) << '\n';
    deleteTree(&root);
    // root = nullptr;
    std::cout << "printTree" << '\n';
    printTree(root);
    return 0;
}