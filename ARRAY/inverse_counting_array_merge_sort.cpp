//https://toph.co/p/count-the-chaos
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll cnt;

void merge_koro(int ar[],int l,int mid,int r)
{
    int ln1=mid-l+1;
    int ln2=r-mid;

    int a[ln1],b[ln2];
    for(int i=0; i<ln1; i++)
    {
        a[i]=ar[l+i];
    }
    for(int i=0; i<ln2; i++)
    {
        b[i]=ar[mid+1+i];
    }

    int i=0,j=0,k=l;

    while(i<ln1 && j<ln2)
    {
        if(a[i]<b[j])
        {
            ar[k]=a[i];
            k++;
            i++;
        }
        else
        {
            ar[k]=b[j];
            k++;
            j++;
            cnt+=(ln1-i);
        }

    }

    while(i<ln1)
    {
        ar[k]=a[i];
        k++;
        i++;

    }

    while(j<ln2)
    {
        ar[k]=b[j];
        k++;
        j++;
    }


}

void merge_srt(int ar[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        merge_srt(ar,l,mid);
        merge_srt(ar,mid+1,r);
        merge_koro(ar,l,mid,r);

    }

}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    cnt=0;
    merge_srt(ar,0,n-1);
    cout<<cnt<<endl;



}
