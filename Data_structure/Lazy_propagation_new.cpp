#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mx=10000;
ll ar[mx+2];

struct info {

ll prop,sum;

}tree[mx*4];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=ar[b];
        return;
    }

    int left=node*2;
    int right=node*2+1;
    ll mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].sum=tree[left].sum+tree[right].sum;

}

void update(int node,int b,int e,int l,int r,ll x)
{
    if(l>e || r<b)
    {
        return;
    }

    if(b>=l && e<=r)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }

    int left=node*2;
    int right=(node*2)+1;
    int mid=(b+e)/2;

    update(left,b,mid,l,r,x);
    update(right,mid+1,e,l,r,x);

    tree[node].sum=tree[left].sum+tree[right].sum+((e-b+1)*tree[node].prop);

}

ll query(int node, int b, int e, int l, int r, ll carry = 0) // carry opor thake nicha jabe
{
    if (l > e || r < b)
        return 0;

    if (b >= l and e <= r)
        return tree[node].sum + carry * (e - b + 1);

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;


    ll p1 = query(left, b, mid, l, r, carry + tree[node].prop);
    ll p2 = query(right, mid + 1, e, l, r, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }

    int m;
    cin>>m;
    init(1,1,n);
    while(m--)
    {
        int type;
        cin>>type;
        if(type==1) // update
        {
            ll b,e,x;
            cin>>b>>e>>x;
            update(1,1,n,b,e,x);
        }
        else if(type==2) //query
        {
            ll b,e;
            cin>>b>>e;
            ll ans= query(1,1,n,b,e);
            cout<<ans<<endl;

        }


    }

}

