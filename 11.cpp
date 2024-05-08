#include <bits/stdc++.h>
using namespace std;

void display(){
    ifstream in("sample.txt");
    string s;
    while(getline(in,s))cout<<s<<endl;
    in.close();
}

void search(vector<int> roll){
    int n;
    cout<<"Enter the number to search: ";
    cin>>n;
    bool flag = 0;
    for(auto i : roll){
        if(i == n){
            cout<<"Present"<<endl;
            flag = 1;
            break;
        }
    }

    if(!flag)cout<<"Not present"<<endl;
}

void del(vector<int> rolln,vector<int> marks,vector<string> nm){
    int n;
    cout<<"Record to delete roll no: ";
    cin>>n;

    ofstream out("sample.txt");
    out<<"Rollno"<<"\t\t"<<"Name"<<"\t\t"<<"Total marks"<<endl;
    for(int i = 0;i<n;i++){
        if(rolln[i] == n){
            rolln[i] = -1;   
        }
        else out<<rolln[i]<<"\t\t"<<nm[i]<<"\t\t"<<marks[i]<<endl;
    }
    out.close();
}   

int main(){
    ofstream out("sample.txt");
    int n;
    cout<<"Total number of students: ";
    cin>>n;
    out<<"Rollno"<<"\t\t"<<"Name"<<"\t\t"<<"Total marks"<<endl;
    vector<int> rolln,marks;
    vector<string> nm;

    for(int i = 0;i<n;i++){
        string name;
        int roll;
        int totalM;
        cout<<"Name: ";
        cin>>name;
        cout<<"Roll: ";
        cin>>roll;
        cout<<"Total marks: ";
        cin>>totalM;
        out<<roll<<"\t\t"<<name<<"\t\t"<<totalM<<endl;
        rolln.push_back(roll);
        marks.push_back(totalM);
        nm.push_back(name);
    }
    out.close();

    while(1){
        cout<<"1.Display"<<endl;
        cout<<"2.Search"<<endl;
        cout<<"3.Delete"<<endl;
        cout<<"Choice: ";
        cin>>n;
        if(n == 1)display();
        else if(n == 2)search(rolln);
        else if(n == 3)del(rolln,marks,nm);
        else break;
    }
}
