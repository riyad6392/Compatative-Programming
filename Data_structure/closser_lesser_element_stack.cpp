#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    stack<pair<int,int>>stk;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(int i=0;i<n;i++)
    {
        while(!stk.empty())
        {
            int pp=stk.top().first;
            if(pp>=ar[i])
            {
                stk.pop();
            }
            else break;

        }
        if(stk.empty())
        {
            cout<<0<<" ";
        }
        else
        {
            int qq=stk.top().second;
            cout<<qq<<" ";
        }
        stk.push(make_pair(ar[i],i+1));

    }
    cout<<endl;



}
