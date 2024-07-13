#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=2e5;
int depth[N+5];
vector<int>vt[N+5];
int ans[N+5];

void dfs(int node,int par)
{
   ans[node]=max(ans[node],depth[node]);
   for(auto a : vt[node])
   {
       if(a==par) continue;
       depth[a]=depth[node]+1;
       dfs(a,node);
   }


}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }

    //part 1
    dfs(1,-1);
    ll mx_dpt=-1;
    int mx_node1;
    for(int i=1;i<=n;i++)
    {
        if(depth[i]>mx_dpt)
        {
            mx_dpt=depth[i];
            mx_node1=i;
        }

    }

    for(int i=1;i<=n;i++)
    {
        depth[i]=0;
    }

    //part 2

    int mx_node2;
    mx_dpt=-1;
    dfs(mx_node1,-1);
    for(int i=1; i<=n; i++)
    {
        if(depth[i]>mx_dpt)
        {
            mx_dpt=depth[i];
            mx_node2=i;
        }

    }
    for(int i=1; i<=n; i++)
    {
        depth[i]=0;
    }

    //part 3
    dfs(mx_node2,-1);

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;







}
