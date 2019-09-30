/*

"""
2 1 1
3 4 2
4 16 8/3
5 84 7/2
6 516 43/10
7 3696 77/15
8 30096 209/35
9 275040 191/28
10 2786400 215/28
11 31000320 299/35

if n odd, try multiplying the fraction by (n-1)(n+3)
"""

import sys
sys.stdin=open("data.txt")
input=sys.stdin.readline

"""
import itertools,fractions
for n in range(8,9):
    tot=0
    cnt=0
    arrt=[0]*n
    for p in itertools.permutations(range(n-1)):
        cnt+=1
        arr=[1]*n
        tmp=0
        rem=n
        for i in p:
            tmp+=1
            if arr[i]:
                arr[i]=0
                rem-=1
            if arr[i+1]:
                arr[i+1]=0
                rem-=1
            if rem==0: break
        tot+=tmp
        arrt[tmp]+=1
        if tmp==3: print(p)
    print(arrt)
    print(n,tot,fractions.Fraction(tot*(n-1)*(n+3))/fractions.Fraction(cnt),tot/cnt)
"""

# O(N log MOD)?
# dp[i] = number of ways to get n-2 letters using i-1 words (a word is A or BB)


n=int(input())
fac=[1]*(n+1)

def choose(i,j):
    # i choose j
    if j<0 or j>i: return 0
    return fac[i]//fac[j]//fac[i-j]

for i in range(2,n+1):
    fac[i]=fac[i-1]*i

dp=[0]*(n+1)
ans=0
carry=0
for i in range(1,n+1):
    dp[i]=choose((i-1),(n-2)-(i-1))*fac[i]*fac[n-1-i]
    if not dp[i]: continue
    ans+=(dp[i]-dp[i-1])*i
print(ans%(10**9+7))
#print(dp)

*/

#include <stdio.h>

const int MOD=1000000007;
typedef long long ll;

int n;
ll fac[1000005];
ll invfac[1000005];

ll powmod(ll a,int b)
{
    if (b==1) return a;
    if (b&1) return (a*powmod((a*a)%MOD,b/2))%MOD;
    return powmod((a*a)%MOD,b/2);
}

ll inv(int i)
{
    return powmod(i,MOD-2);
}

ll choose(int i,int j)
{
    if (j<0 || j>i) return 0;
    return (((fac[i]*invfac[j])%MOD)*invfac[i-j])%MOD;
}

ll dp[1000005];
ll ans=0;

int main()
{
    #ifdef NOT_DMOJ
    freopen("data.txt","r",stdin);
    #endif // NOT_DMOJ
    scanf("%d",&n);
    fac[0]=1;
    invfac[0]=1;
    fac[1]=1;
    invfac[1]=1;
    for (int i=2; i<=n; i++) {
        fac[i]=(fac[i-1]*i)%MOD;
        invfac[i]=(invfac[i-1]*inv(i))%MOD;
    }
    for (int i=1; i<=n; i++) {
        dp[i]=(((choose(i-1,n-2-(i-1))*fac[i])%MOD)*fac[n-1-i])%MOD;
        if (!dp[i]) continue;
        ans+=(dp[i]-dp[i-1])*i;
        ans%=MOD;
    }
    printf("%lld\n",(ans+MOD)%MOD);     // negative ans is possible
}