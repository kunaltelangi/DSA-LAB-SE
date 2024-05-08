#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> adjlist,int n){
    queue<int> q;
    vector<bool> vist(n,0);
    vist[0] = 1;
    q.push(0);
    cout<<"BFS: ";
    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout<<f<<" ";
        for(auto i : adjlist[f]){
            if(!vist[i]){
                vist[i] = 1;
                q.push(i);
            }
        }
    }
}

void dfs(vector<vector<int>> adjlist,int n,vector<int> &ans,int vist[],int node){
    vist[node] = 1;
    ans.push_back(node);
    for(auto i : adjlist[node]){
        if(!vist[i]){
            dfs(adjlist,n,ans,vist,i);
        }
    }
}

int main(){
    int n;
    cout<<"Enter total number of nodes: ";
    cin>>n;
    vector<vector<int>> adjlist(n); 
    for(int i = 0;i<n;i++){
        vector<int> temp;
        cout<<"Node connected to "<<i<<": ";
        int d = 0;
        while(d != -1 && d<n){
            cin>>d;
            temp.push_back(d);
        }
        temp.pop_back();
        adjlist[i] = temp;
    }
    bfs(adjlist,n);
    vector<int> ans;
    int node = 0;
    int vist[n] = {0};
    dfs(adjlist,n,ans,vist,node);
    cout<<endl;
    cout<<"DFS: ";
    for(auto i :ans)cout<<i<<" ";
    return 0;
}
