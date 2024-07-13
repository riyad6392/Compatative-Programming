#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int>f(vector<int>v)
{
    if(v.size()==1) return v;
    vector<int>v1,v2;
    int half=v.size()/2;
    for(int i=0;i<half;i++)
    {
        v1.push_back(v[i]);
    }
    for(int i=half;i<v.size();i++)
    {
        v2.push_back(v[i]);
    }
    v1=f(v1);
    v2=f(v2);
    v.clear();
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    while(!v1.empty() || !v2.empty())
    {
        if(v1.size()>=1 && v2.size()>=1)
        {
            if(v1.back()<=v2.back())
            {
                v.push_back(v1.back());
                v1.pop_back();
            }
            else
            {
                v.push_back(v2.back());
                v2.pop_back();
            }
        }
        else if(v1.empty())
        {
            v.push_back(v2.back());
            v2.pop_back();
        }
        else if(v2.empty())
        {
            v.push_back(v1.back());
            v1.pop_back();
        }


    }
    return v;

}

int main()
{
    int n;
    cin>>n;
    vector<int>vt(n);
    for(int i=0;i<n;i++)
    {
        cin>>vt[i];

    }
    vt=f(vt);
    for(int i=0;i<n;i++)
    {
        cout<<vt[i]<<" ";
    }
    cout<<endl;


}
