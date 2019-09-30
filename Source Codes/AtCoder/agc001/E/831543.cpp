#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <bitset>
#include <queue>
#include <set>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

#define LL long long
#define ULL unsigned long long
#define eps 1e-9
#define N 201000
#define M 600050
#define pii pair<int,int>
#define MP make_pair
#define inf 0x3f3f3f3f
#define md ((ll+rr)>>1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define ls rt<<1
#define rs rt<<1|1
#define Pi acos(-1.0)
#define mod 1000000007
#define ui unsigned int
// curiosity , go.
LL powmod(LL a,LL b,LL p){
    if(b < 0) return 0;
    LL res = 1; a %= p;
    for(;b;b>>=1){
        if(b & 1) res = res * a % p;
        a = a * a % p;
    }
    return res;
}

int dp[4010][4010],vis[4010][4010];
int fac[8010],invf[8010];

void add(int &a,int b){
    a += b;
    if(a >= mod) a -= mod;
}

int main(){
    int n;
    fac[1] = invf[1] = 1;
    for(int i = 2; i <= 8000; i++){
        fac[i] = 1LL * fac[i - 1] * i % mod;
        invf[i] = (int)powmod(fac[i], mod-2, mod);
    }
    scanf("%d",&n);
    int ans = 0;
    for(int i = 1,x,y; i <= n; i++){
        scanf("%d%d",&x,&y);
        dp[2000-x][2000-y]++;
        vis[2000+x][2000+y]++;
        ans -= 1LL * fac[2*x+2*y] * invf[2*x] % mod * invf[2*y] % mod;
        if(ans < 0) ans += mod;
    }
    //cout<<mod - ans<<endl;
    for(int i = 0; i <= 4000; i++)
        for(int j = 0; j <= 4000; j++){
            if(i >= 1) add(dp[i][j],dp[i-1][j]);
            if(j >= 1) add(dp[i][j],dp[i][j-1]);
            if(vis[i][j]) add(ans, 1LL * dp[i][j] * vis[i][j] % mod);
        }
    printf("%d\n",1LL * ans * powmod(2, mod - 2, mod) % mod);
} ./Main.cpp:73:19: warning: format specifies type 'int' but the argument has type 'long long' [-Wformat]
    printf("%d\n",1LL * ans * powmod(2, mod - 2, mod) % mod);
            ~~    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            %lld
1 warning generated.