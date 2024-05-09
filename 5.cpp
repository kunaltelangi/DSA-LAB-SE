#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int val;
        node* left;
        node* right;
        bool isThreaded;
        node(int val){
            this->val  = val;
            this->right = NULL;
            this->left = NULL;
            this->isThreaded = false;
        }
};

node* createThreaded(node* root){
    if(root == NULL)return NULL;
    if(root->left == NULL && root->right == NULL)return root;
    if(root->left != NULL){
        node* temp = createThreaded(root->left);
        temp->right = root;
        temp->isThreaded = true;
    }
    if(root->right == NULL)return root;
    return createThreaded(root->right);
}

node* createTree(node* root){
    int d;
    cout<<"Enter the data for the tree: ";
    cin>>d;
    root = new node(d);
    if(d == -1)return NULL;
    cout<<"Enter the value left part of "<<d<<endl;
    root->left = createTree(root->left);
    cout<<"Enter the value right part of "<<d<<endl;
    root->right = createTree(root->right);

    return root;
}

node* leftMost(node* root){
    while(root != NULL && root->left != NULL)root = root->left;
    return root;
}

void inOrder(node* root){
    if(root == NULL)return;
    node* curr = leftMost(root);
    while(curr!=NULL){
        cout<<curr->val<<" ";
        if(curr->isThreaded)curr = curr->right;
        else curr = leftMost(curr->right);
    }
}

int main() {
    node* root = NULL;
    root = createTree(root);
    createThreaded(root);
    inOrder(root);
    return 0;
}
