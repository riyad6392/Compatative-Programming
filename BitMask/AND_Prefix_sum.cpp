#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;

    vector<vector<int>>vt(200001);

        for(int j=0;j<=29;j++)
        {
            vt[0].push_back(0);
        }

    for(int i=1;i<=200000;i++)
    {
        bitset<30>bts(i);
        int p=0;
        for(int j=29;j>=0;j--)
        {
            //cout<<bts[j];
            //p+=bts[j];
            int pp=vt[i-1][j]+bts[j];
            vt[i].push_back(pp);
        }
       reverse(vt[i].begin(),vt[i].end());
        //cout<<endl;
        //cout<<bts<<endl;
        //cout<<p<<endl;
       //  for(int j=0;j<=29;j++)
       // {
        //    cout<<vt[i][j];
       // }
       // cout<<endl;
       // cout<<endl;
    }




    cin>>t;
    while(t--)
    {
      int l,r;
      cin>>l>>r;
      int mx=0;
      for(int i=0;i<=29;i++)
      {
        int q=vt[r][i]-vt[l-1][i];
        mx=max(mx,q);
      }
      int x=r-l+1;
      int ans=x-mx;
      cout<<ans<<endl;

    }

}
