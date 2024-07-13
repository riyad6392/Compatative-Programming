#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=100000;
int tree[N+5];
int ar[N+5];

int  BIT_query(int indx)   // 1 thake indx porjonto sum bar kore deba
{
    int sum=0;
    while(indx>0)
    {
      sum+=tree[indx];
      indx-=(indx & (-indx));

    }
    return sum;

}

void BIT_update(int n,int indx,int vlu)  // indx position a value add korbe
{
   while(indx<=n)
   {
       tree[indx]+=vlu;
       indx+=(indx & (-indx));
   }
}

void BIT_build(int n)
{
    for(int i=1;i<=n;i++)
    {
        BIT_update(n,i,ar[i]);

    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n,m;
        cin>>n>>m;
        tree[0]=0;
        //ar[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>ar[i];
            tree[i]=0;
        }
        BIT_build(n);
        cout<<"Case "<<c<<":"<<endl;

        while(m--)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                int d_vlu;
                cin>>d_vlu;
                int pp=ar[d_vlu+1]; // 1 base index
                ar[d_vlu+1]=0;
                cout<<pp<<endl;
                BIT_update(n,d_vlu+1,-pp);

            }
            else if(x==2)
            {
                int vlu,loc;
                cin>>loc>>vlu;

                ar[loc+1]=ar[loc+1]+vlu;
                BIT_update(n,loc+1,vlu);


            }
            else
            {
                int lf,rf;
                cin>>lf>>rf;

                int ful=BIT_query(rf+1);
                int bk=BIT_query(lf);

                int ans=ful-bk;

                cout<<ans<<endl;


            }


        }


    }

}
