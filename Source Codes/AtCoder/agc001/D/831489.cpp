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
#define N 2010
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

int a[N];
int ans[N],ansa[N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int odd = 0;
    for(int i = 1; i <= m; i++){
        scanf("%d",&a[i]);
        odd += a[i] & 1;
    }
    if(odd > 2){
        puts("Impossible");
        return 0;
    }
    int st = 0,tot = 0,tota = 0;
    if(odd > 0){
        for(int i = 1; i <= m; i++)
            if(a[i] & 1) st = i;
        ansa[++tota] = a[st];
        if(a[st] != 1) ans[++tot] = a[st] - 1;
        for(int i = 1; i <= m; i++){
            if(!(a[i] & 1)){
                ans[++tot] = a[i];
                ansa[++tota] = a[i];
            }
        }
        for(int i =1; i <= m; i++)
            if(i != st && a[i] & 1) ans[++tot] = a[i] + 1,ansa[++tota] = a[i];
        if(odd == 1){
            if(m == 1) ans[++tot] = 1;
            else ans[tot]++;
        }
    }
    else{
        int now = 0;
        ans[++tot] = a[1] - 1;
        now += a[1] - 1;
        ansa[1] = a[1];
        for(int i = 2; i < m; i++)
            ans[++tot] = a[i], now += a[i],ansa[i] = a[i];
        ans[++tot] = n - now;
        ansa[m] = a[m];
    }
    for(int i = 1; i <= m; i++)
        printf("%d%c",ansa[i],i == m ? '\n' : ' ');
    printf("%d\n",tot);
    for(int i = 1; i <= tot; i++)
        printf("%d%c",ans[i],i == tot ? '\n' : ' ');
    return 0;
}