#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    // File input and outputs :
    //Fin ; Fout ;
    //given  five coins with weight.. how many possible way to make with them n (not different).
    int coin[10];
    coin[1] = 1;
    coin[2] = 5;
    coin[3] = 10;
    coin[4] = 25;
    coin[5] = 50;
    ll way[10000];
    way[0] = 1;
    for(int i = 1; i <= 8000 ; i++){
        for(int j = 1; j <= 5 ; j++){
            if(i >= coin[j])
                way[i] += way[i-coin[j]];
        }
    }
    int n;
    while(cin >> n){
        cout << way[n] << "\n";
    }
    return 0;
}
