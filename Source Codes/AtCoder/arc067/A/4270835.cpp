#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define MOD 1000000007
using namespace std;
int prime[1005];
int check[1005];
int tot = 0;
void olsf(){
    for (int i = 2; i < 1005; ++i)
    {
        if(!check[i])prime[tot++] = i;
        for (int j = 0; j < tot; ++j)
        {
            if (i * prime[j] > 1005)break;
            check[i*prime[j]] = 1;
            if (i % prime[j] == 0)break;
        }
    }
}
int a[1005];
int main()
{
    olsf();
    ll n, t;
    cin>>n;
    t = n;
    ll ans = 1;
    for(int i = 2; i <= t; i++){
        int temp = i;
        for(int j = 2; j <= temp; j++){
            while(!check[j] && temp % j == 0){
                a[j]++;
                temp/=j;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i] != 0)ans = ans*(a[i]+1)%MOD;
    }
    cout<<ans;

    return 0;
}