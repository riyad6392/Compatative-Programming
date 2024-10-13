#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s[n];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];

    }

    int sr=0,di=0;
    int rig=n,lef=1;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            if(s[lef]>=s[rig])
            {
                sr=sr+s[lef];
                lef++;
            }
            else
            {
                sr=sr+s[rig];
                rig--;

            }

        }
        else
        {
            if(s[lef]>=s[rig])
            {
                di=di+s[lef];
                lef++;
            }
            else
            {
                di=di+s[rig];
                rig--;

            }

        }


    }
    cout<<sr<<" "<<di<<endl;

}
