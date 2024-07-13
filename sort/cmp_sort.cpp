//_LOJ 1053 - False Ordering
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first!=b.first)
    {
        return a.first<b.first; // boro hole > hobe
    }
    else return a.second>b.second;
}
int main()
{
    vector<pair<int,int>>vt;
    for(int i=1;i<=1000;i++)
    {
         vt.push_back(make_pair(0,0));
    }
    for(int i=1;i<=1000;i++)
    {
        vt[i-1].second=i;
        for(int j=i;j<=1000;j+=i)
        {
            vt[j-1].first++;
        }
    }
    sort(vt.begin(),vt.end(),cmp);
   /* for(int i=0;i<=10;i++)
    {
        cout<<vt[i].first<<" "<<vt[i].second<<endl;
    }
    */

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<i<<": "<<vt[n-1].second<<endl;


    }



}
