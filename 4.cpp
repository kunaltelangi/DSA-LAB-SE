#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* right;
        node* left;
        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
node* insert(node* root,int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }
    if(d > root->data)root->right = insert(root->right,d);
    else root->left = insert(root->left,d);
    return root;
}

void pre(node* root){
    if(root == NULL)return;
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

int longPath(node* root){
    if(root == NULL)return 0;
    int r = longPath(root->right);
    int l = longPath(root->left);
    return max(l,r)+1;
}

bool search(node* root,int d){
    if(root == NULL)return 0;
    if(root->data == d)return 1;
    if(root->data < d)search(root->right,d);
    else search(root->left,d);
}
void fdmin(node* root){
    while(root->left != NULL)root = root->left;
    cout<<root->data<<endl;
}

void takeip(node* &root){
    int d;
    cout<<"ENter the data: ";
    cin>>d;
    while(d != -1){
        root = insert(root,d);
        cout<<"ENter the data: ";
        cin>>d;
    }
}
void swp(node* &root){
    if(root == NULL)return;
    swap(root->right,root->left);
    swp(root->left);
    swp(root->right);
}
int main(){
    node* root = NULL;
    takeip(root);
    pre(root);
    cout<<endl;
    cout<<longPath(root)<<endl;
    cout<<search(root,5)<<endl;
    fdmin(root);
    swp(root);
    pre(root);
}
