#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       vector<ll>bit(32,0);
       for(int i=0;i<n;i++)
       {
           int x;
           cin>>x;
           for(int j=0;(1<<j)<=x;j++)
           {
               if(x&(1<<j))
               {
                   bit[j]++;
               }

           }
       }
       vector<ll>ans;
       for(int i=1;i<=n;i++)
       {
           int fg=0;
           for(int j=0;j<32;j++)
           {
               if(bit[j]%i)
               {
                   fg=1;
                   break;
               }
           }
           if(fg==0)
           {
               ans.push_back(i);
           }
       }
       for(auto a : ans)
       {
           cout<<a<<" ";
       }
       cout<<endl;

    }

}
