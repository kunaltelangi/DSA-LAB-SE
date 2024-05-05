#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#define gcj "Case #"
#define adj_list vector<vi>
#define endl "\n"
#define spc " "
#define INF_INT 2e9
#define INF_LL 2e18
#define matmax 25
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pi pair<int, int>
#define pip pair<int,pi>
#define pl pair<ll,ll>
#define plp pair<ll,pl>
#define vi vector<int>
#define vl vector<ll>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define ins insert
#define lb lower_bound  // First element NOT LESS than val
#define ub upper_bound  // First element GREATER than val
#define sz(q) (int)(q.size())
 
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef long int li;

#define ook order_of_key  // Number of elements STRICTLY smaller than X
#define fbo find_by_order  //  *ITERATOR* pointing to the kth element (0 order)

#define fo(a,b) for(auto i=a;i<b;++i)
#define nfo(a,b) for(auto i=a;i>=b;--i)
#define jfo(a,b) for(auto j=a;j<b;++j)
#define njfo(a,b) for(auto j=a;j>=b;--j)
#define tt ll t; cin>>t; while(t--)

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
