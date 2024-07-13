#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int main()
{
    faster
    ll n,q;
    cin>>n>>q;
    map<int,int>r,c;
    ordered_set row,col;
    while(q--)
    {
        ll m;
        cin>>m;
        if(m==1)
        {
           int x,y;
           cin>>x>>y;
           row.insert(x);
           col.insert(y);
           r[x]++;
           c[y]++;
        }
        else if(m==2)
        {
           int x,y;
           cin>>x>>y;
           r[x]--;
           c[y]--;
          if(r[x]==0)row.erase(x);
          if(c[y]==0) col.erase(y);

        }
        else if(m==3)
        {
           int x1,y1,x2,y2;
           cin>>x1>>y1>>x2>>y2;
           int pp=row.order_of_key(x2+1)-row.order_of_key(x1);
           int qq=col.order_of_key(y2+1)-col.order_of_key(y1);
           if((x2-x1+1)==pp)
           {
               cout<<"Yes"<<endl;
           }
           else if((y2-y1+1)==qq)
           {
               cout<<"Yes"<<endl;
           }
           else
           {
               cout<<"No"<<endl;
           }
        }

    }

}

