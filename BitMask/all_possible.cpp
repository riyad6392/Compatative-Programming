#include<bits/stdc++.h>
#define ll long long int
#define SetBit(x, k) (x |= (1 << k))
#define ClearBit(x, k) (x &= ~(1 << k))
#define CheckBit(x, k) (x & (1 << k))
int log(ll x){ return __builtin_clzll(1ll) - __builtin_clzll(x); } // log2(x) ar kaj kore,,,log2() tle dai maje maje
using namespace std;
int main()
{
   ll n;
   cin>>n;
   ll pp=pow(2,n);
   ll ar[n];
   for(int i=0;i<n;i++)
   {
   cin>>ar[i];
   }
   ll mn=LONG_MAX;
   for(ll i=1;i<=pp;i++)
   {
     bitset<21>bit(i);
     ll sm1=0,sm2=0;
     for(ll j=0;j<21 && j<n;j++)
     {
        if(bit[j]) sm1+=ar[j];
        else sm2+=ar[j];
     }
     mn=min(mn,abs(sm1-sm2));

   }
   cout<<mn<<endl;

}

