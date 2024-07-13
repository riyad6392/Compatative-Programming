#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        int lf[n],rg[n];
        stack<int>stk;
        for(int i=0;i<n;i++)
        {
            while(!stk.empty())
            {
                int p=stk.top();
                if(ar[p]>=ar[i])  //increasing order a jabe
                {
                    stk.pop();
                }
                else
                {
                    break;
                }

            }

            if(stk.empty())
            {
                lf[i]=0;
            }
            else
            {
                lf[i]=stk.top()+1;
            }
            stk.push(i);

        }

        while(!stk.empty())
        {
            stk.pop();
        }

        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty())
            {
                int pp=stk.top();
                if(ar[pp]>=ar[i])
                {
                    stk.pop();
                }
                else
                {
                    break;
                }

            }
            if(stk.empty())
            {
                rg[i]=n-1;
            }
            else
            {
                rg[i]=stk.top()-1;
            }
            stk.push(i);

        }

        ll area=0;
        for(int i=0;i<n;i++)
        {
            ll dd=rg[i]-lf[i]+1;
            dd=(dd*ar[i]);
            area=max(area,dd);
        }
        cout<<"Case "<<tt<<": "<<area<<endl;


    }

}
