#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int m = 10;
void insert(ll x,ll (&h)[m]){
    int i = x%m;
    while(h[i] != 0 && h[i] != -1)i = (i+1)%m;
    h[i] = x;
    return;
}

bool search(ll x,ll (&h)[m]){
    int i = x%m;
    int j = i;
    while(h[i] != 0 && h[i] != x){
        i = (i+1)%m;
        if(i == j)return 0;
    }
    return h[i] == x;
}

void del(ll x,ll (&h)[m]){
    bool f = search(x,h);
    if(f){
        int i = x%m;
        while(h[i] != x)i = (i+1)%m;
        h[i] = -1;
        cout<<"Deleted"<<endl;
    }
}

void modify(ll x,ll y,ll (&h)[m]){
    bool f = search(x,h);
    if(f){
        int i = x%m;
        while(h[i] != x)i = (i+1)%m;
        h[i] = y;
        cout<<"modified"<<endl;
    }
    else cout<<"Not present to modify"<<endl;
}

int main(){
    ll h[m] = {0};
    int n;
    cout<<"Enter the number of entries: ";
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cout<<"Enter the tel num: ";
        ll x;
        cin>>x;
        insert(x,h);
    }
    while(1){
        cout<<"1.search"<<endl;
        cout<<"2.modify"<<endl;
        cout<<"3.delete"<<endl;
        cout<<"4.exit"<<endl;
        int m;
        cin>>m;
        if(m==1){
            cout<<"Enter tel to search: ";
            ll t;
            cin>>t;
            bool f = search(t,h);
            if(f)cout<<"Present"<<endl;
            else cout<<"Not present"<<endl;
        }
        else if(m == 2){
            ll a,b;
            cout<<"Enter old no. : ";
            cin>>a;
            cout<<"Enter new no. : ";
            cin>>b;
            modify(a,b,h);
        }
        else if(m == 3){
            ll t;
            cout<<"Enter tel no. to delete: ";
            cin>>t;
            del(t,h);
        }
        else break;
    }

}
