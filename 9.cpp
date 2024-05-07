#include <bits/stdc++.h>
using namespace std;

class node {
public:
    string name;
    int val;
    int height;
    node* right;
    node* left;

    // Constructor
    node(string name, int val) {
        this->name = name;
        this->val = val;
        this->right = NULL;
        this->left = NULL;
        this->height = 1;
    }
};

// Function to get height of a node
int getH(node* root) {
    if (root == NULL) return 0;
    return root->height;
}

// Function to calculate balance factor of a node
int bf(node* root) {
    if (root == NULL) return 0;
    return getH(root->left) - getH(root->right);
}

// Right Rotation
node* RR(node* root) {
    node* child = root->left;
    node* childright = child->right;

    child->right = root;
    root->left = childright;

    // Update height of nodes after rotation
    root->height = max(getH(root->left), getH(root->right)) + 1;
    child->height = max(getH(child->left), getH(child->right)) + 1;

    return child;
}

// Left Rotation
node* LR(node* root) {
    node* child = root->right;
    node* childleft = child->left;

    child->left = root;
    root->right = childleft;

    // Update height of nodes after rotation
    root->height = max(getH(root->left), getH(root->right)) + 1;
    child->height = max(getH(child->left), getH(child->right)) + 1;

    return child;
}

// Function to insert a node
node* insert(node* root, int val, string name) {
    if (root == NULL) {
        root = new node(name, val);
        return root;
    }

    // Recursively insert the node
    if (val > root->val)
        root->right = insert(root->right, val, name);
    else
        root->left = insert(root->left, val, name);

    // Update height of current node
    root->height = 1 + max(getH(root->left), getH(root->right));
    int BF = bf(root);

    // Perform rotations if needed to maintain balance

    // Left Left Case
    if (BF > 1 && val < root->left->val)
        return RR(root);

    // Right Right Case
    if (BF < -1 && val > root->right->val)
        return LR(root);

    // Left Right Case
    if (BF > 1 && val > root->left->val) {
        root->left = LR(root->left);
        return RR(root);
    }

    // Right Left Case
    if (BF < -1 && val < root->right->val) {
        root->right = RR(root->right);
        return LR(root);
    }

    return root;
}

// Function to print tree in pre-order
void pre(node* root) {
    if (root == NULL) return;
    cout << root->val << "  " << root->name << endl;
    pre(root->left);
    pre(root->right);
}

int main() {
    node* root = NULL;
    int n;
    int val;
    string name;

    while (true) {
        cout << "1.Insert" << endl;
        cout << "2.Display" << endl;
        cout << "3.Exit" << endl;
        cout << "Choice: ";
        cin >> n;

        if (n == 1) {
            cout << "Enter the key and value: ";
            cin >> val >> name;
            root = insert(root, val, name);
        } else if (n == 2) {
            cout << "Tree in pre-order:" << endl;
            pre(root);
        } else {
            break;
        }
    }

    return 0;
}
