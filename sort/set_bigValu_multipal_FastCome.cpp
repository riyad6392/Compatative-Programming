#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    set<pair<int,int>>st;
    set<int>s;
    int p=1;
    int ar[n+1];
    while(n--)
    {
        int m;
        cin>>m;
        if(m==1)
        {
            int k;
            cin>>k;
            ar[p]=k;
            st.insert({k,p*(-1)}); // comp sort
            s.insert(p);
            p++;

        }
        else if(m==2)
        {
            int pp=*s.begin();
            s.erase(s.begin());
           // s.erase(s.find(pp));
            cout<<pp<<" ";
            st.erase(st.find({ar[pp],pp*(-1)}));
        }
        else if(m==3)
        {
            auto it=st.end();
            it--;
             int x=it->first;
             int y=it->second;
           // auto [x,y]= *it;
            y*= -1;
            cout<<y<<" ";
            s.erase(s.find(y));
           // st.erase(st.find({ar[y],y*(-1)}));
            st.erase(it);

        }

    }
    cout<<endl;


}
