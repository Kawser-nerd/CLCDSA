//#include <bits/stdc++.h>
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long LL;

const int mod=1e9+7;

int a[1010],num;
LL bit[1010];

bool isprime(int x){
    if(x==1) return false;
    int q=sqrt(x);
    for(int i=2;i<=q;i++)
        if(x%i==0) return false;
    return true;
}

void init(){
    num=0;
    for(int i=1;i<=1000;i++)
        if(isprime(i)) a[num++]=i;
}

void solve(int n){
    for(int i=0;i<num;i++){
        if(n%a[i]) continue;
        while(n%a[i]==0){
            bit[i]++;
            n/=a[i];
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    if(n==1){
        puts("1");
        return 0;
    }
    init();
    for(int i=0;i<num;i++)
        bit[i]=1;
    for(int i=2;i<=n;i++){
        solve(i);
    }
    LL ans=1;
    for(int i=0;i<num;i++){
        ans=ans*bit[i]%mod;
    }
    printf("%lld\n",ans);
    return 0;
}