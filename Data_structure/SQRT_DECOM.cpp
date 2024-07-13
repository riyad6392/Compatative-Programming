#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int pp=sqrt(n)+1;
    vector<int>vt(pp);
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        vt[i/pp]+=ar[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        int sum=0;
        for(int i=l;i<=r; )
        {
            if(i%pp==0 && i+pp-1<=r)
            {
                sum+=vt[i/pp];
                i+=pp;
            }
            else
            {
                sum+=ar[i];
                i++;
            }

        }
        cout<<sum<<endl;
    }

}
