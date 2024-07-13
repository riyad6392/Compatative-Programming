#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll Hash(const string &s,int m,ll B,ll M) //m =string.size()
{
   ll has=0;
   ll power=1;
   for(int i=m-1;i>=0;i--) // pison thake shoro korte hobe karo power_count
   {
       has=has+(s[i]*power)%M;
       has=has%M;
       power=(power*B)%M;

   }
   return has;
}

void solve(const string &text,const string &pat)
{
    ll B=347,M=1000000007;
    int m=pat.size();
    int n=text.size();
    if(m>n)
    {
        cout<<"NO"<<endl;
    }
    else if(n==0 or m==0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
      ll hash_text=Hash(text,m,B,M);
      ll hash_pat=Hash(pat,m,B,M);
      cout<<hash_text<<" "<<hash_pat<<endl;
      if(hash_text==hash_pat)
      {
          cout<<"YES"<<endl; //jodi prothomai paiya jai
      }
      else
      {
          ll power=1;
          for(int i=1;i<=m-1;i++)
          {
              power=(power*B)%M;
          }
         for(int i=m;i<n;i++)
         {
         //Update Rolling Hash
         hash_text=(hash_text-(power*text[i-m])%M)%M;
         hash_text=(hash_text+M)%M; // for negative value
         hash_text=(hash_text*B)%M;
         hash_text=(hash_text+text[i])%M;
        if(hash_text==hash_pat)
        {
            //check every char for collision
            cout<<"YES"<<endl;
            cout<<i-m+1<<endl;
            break;
        }

         }

      }

    }



}

int main()
{
     string text,pat;
    cin>>text>>pat;
    solve(text,pat);
}

