#include <bits/stdc++.h>
using namespace std;

int i = 0;
int j = 0;
int const n = 100;
int mx[n+1];
int mn[n+1];

void insertMX(int d){
    i = i+1;
    mx[i] = d;
    while(i > 1){
        int parent = i/2;
        if(mx[i] > mx[parent]){
            swap(mx[i], mx[parent]);
            i = parent; // Update current index
        }
        else return;
    } 
}

void insertMN(int d){
    j = j+1;
    mn[j] = d;
    while(j > 1){
        int parent = j/2; // Corrected from 'i' to 'j'
        if(mn[j] < mn[parent]){
            swap(mn[j], mn[parent]);
            j = parent; // Update current index
        }
        else return;
    } 
}

int main(){
    cout << "Total number of nodes: ";
    int a;
    cin >> a;
    cout << "Enter the nodes: ";
    int x;

    for(int k = 0; k < a; k++){
        cin >> x;
        insertMX(x);
        insertMN(x);
    }

    cout << "MAX: " << mx[1] << endl;
    cout << "MIN: " << mn[1] << endl;

    return 0;
}
