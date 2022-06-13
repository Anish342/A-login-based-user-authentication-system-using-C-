#include <bits/stdc++.h>
using namespace std;

int hash1(string s)
{
    int b=s[0]*1+s[1]*2+s[2]*3;
    b=b%97;
    return b;
}

int main()
{
    int n=97;
    vector<pair<string,string>> V[n];
    string s,s1;
    fstream fin;
    fin.open("userInfo.csv",ios::in);
    while(!fin.eof())
    {
        getline(fin,s);
        pair<string,string> k;
        stringstream ss(s);
        string user_name,password;
        getline(ss,user_name,',');
        k.first=user_name;
        getline(ss,password,',');
        k.second=password;
        int temp=hash1(k.first);
        V[temp].emplace_back(k);
    }
    int c=0;
    cout<<"Please enter your username:";
    cin>>s;
    n=hash1(s);
    for(int i=0;i<V[n].size();i++)
    {
        if(s==V[n][i].first)
        {
            c=1;
            cout<<"Please Enter your Password:";
            cin>>s1;
            if(s1==V[n][i].second)
            {
                cout<<"LOGIN SUCCESSFUL!";
                break;
            }
            else{
                cout<<"INCORRECT PASSWORD";
                break;
            }
        }
    }
    if(c==0)
    {
        cout<<"NAME NOT FOUND";
    }
    return 0;
}
