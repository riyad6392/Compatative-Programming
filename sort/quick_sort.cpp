#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int partition(int ar[],int low,int high)
{
    int i=low-1;
    int vlu = ar[high];

    for(int j=low;j<high;j++)
    {
        if(ar[j]<vlu)
        {
            i++;
            swap(ar[i],ar[j]);
        }
    }

    swap(ar[i+1],ar[high]);

    return i+1;

}

void quick_sort(int ar[], int low, int high)
{
    if(low<high)
    {

        int pivot = partition(ar,low,high);
        quick_sort(ar,low,pivot-1);
        quick_sort(ar,pivot+1,high);
    }

}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    quick_sort(ar,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;


}
