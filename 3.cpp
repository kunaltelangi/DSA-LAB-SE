#include<bits/stdc++.h>
using namespace std;
class node {
public:
    string name;
    node* next;
    node* down;
    node(string name) {
        this->name = name;
        this->next = NULL;
        this->down = NULL;
    }
};

void insert(node* &tail, string s) {
    node* t = new node(s);
    if (tail != NULL)
        tail->next = t;
    tail = t;
}

void insertD(node* &head, string s) {
    node* temp = head;
    while (temp != NULL && temp->name != s)
        temp = temp->next;
    if (temp != NULL) {
        string x;
        cout << "Enter subchapter name: ";
        cin >> x;
        node* t = new node(x);
        if (temp->down == NULL)
            temp->down = t;
        else {
            node* tempDown = temp->down;
            while (tempDown->next != NULL)
                tempDown = tempDown->next;
            tempDown->next = t;
        }
    } else {
        cout << "Chapter not found!" << endl;
    }
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->name << endl;
        node* subchapter = temp->down;
        while (subchapter != NULL) {
            cout << "\t" << subchapter->name << endl;
            subchapter = subchapter->next;
        }
        temp = temp->next;
    }
}

int main() {
    string s;
    cout << "Enter the book name: ";
    cin >> s;
    node* head = new node(s);
    node* tail = head;
    while (true) {
        int n;
        cout << "1.chapter" << endl;
        cout << "2.subchapter" << endl;
        cout << "3.display" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter the choice: ";
        cin >> n;
        if (n == 1) {
            cout << "Chapter name: ";
            cin >> s;
            insert(tail, s);
        } else if (n == 2) {
            cout << "Chapter name to have subchapter: ";
            cin >> s;
            insertD(head, s);
        } else if (n == 3) {
            display(head);
        } else {
            break;
        }
    }
    return 0;
}
