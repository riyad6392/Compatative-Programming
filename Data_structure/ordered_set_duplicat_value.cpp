//https://cses.fi/problemset/task/1076
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type,
        less<pair<int,int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set_pair;
int main()
{
    faster
    ll n,q;
    cin>>n>>q;
    ordered_set_pair mySet;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];

    }
    for(int i=0;i<q;i++)
    {
        mySet.insert(make_pair(ar[i],i));
    }
    ll p;
    if(q%2==0)
    {
        p=q/2;
        p--;
    }
    else
    {
        p=q/2;
    }
    int pp=0;
    auto it = mySet.find_by_order(p);
    cout<<(*it).first<<" ";
    for(int i=q;i<n;i++)
    {
       mySet.erase(mySet.find({ar[pp],pp}));
       pp++;
       mySet.insert(make_pair(ar[i],i));
       auto it2=mySet.find_by_order(p);
       cout<<(*it2).first<<" ";
    }
    cout<<endl;





}

