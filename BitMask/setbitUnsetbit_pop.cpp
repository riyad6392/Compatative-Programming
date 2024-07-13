// given n,you have to find x, x<=n, x=(exxatli 3 set bit), x is maximum;
//https://atcoder.jp/contests/arc161/tasks/arc161_b
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
        ll bt=__builtin_popcountll(n); // long long so you have to use ll
        //cout<<bt<<endl;
        if(n<7)
        {
            cout<<-1<<endl;
        }
        else if(bt==3)
        {
            cout<<n<<endl;
        }
        else if(bt>3)
        {
          bitset<63>btt(n);
          for(int i=0;i<=63;i++)
          {
              if(bt==3)break;
              if((n & (1LL<<i))!=0)
              {
                  bt--;
                  n=(n&(~(1LL<<i))); // set bit ree unset korsi
              }
          }
          cout<<n<<endl;
          ll bk=__builtin_popcountll(n);
          //cout<<bk<<endl;

        }
        else if(bt==1)
        {
            // 1000000 re  0111000 korsi
            ll kl=0;
            for(ll i=63;i>=0;i--)
            {
               if((n & (1LL<<i))!=0)
              {
                  i--;
                 kl+=(1LL<<i);
                 i--;
                 kl+=(1LL<<i);
                 i--;
                 kl+=(1LL<<i);
                 break;
              }
            }
            cout<<kl<<endl;

        }
        else if(bt==2)
        {
             if(((n & (1<<0))!=0) || ((n & (1<<1))!=0))  // jodi amon 100001 or 100010 hoi taila 011100 hobe
             {
                  ll kl=0;
             for(ll i=63;i>=0;i--)
            {
               if((n & (1LL<<i))!=0)
              {
                  i--;
                 kl+=(1LL<<i);
                 i--;
                 kl+=(1LL<<i);
                 i--;
                 kl+=(1LL<<i);
                 break;
              }
            }
            cout<<kl<<endl;

             }
             else
             {
            // jod amon hoi 10000100 or 1001000 hoi taila 100100=100011, 1001000=1000110
            for(ll i=0;i<=63;i++)
           {
              if((n & (1LL<<i))!=0)
              {
                  n=(n&(~(1LL<<i)));
                  i--;
                  n=(n | (1LL<<i));
                  i--;
                 n=(n | (1LL<<i));
                 break;

              }
           }
          cout<<n<<endl;


             }



        }


    }

}

