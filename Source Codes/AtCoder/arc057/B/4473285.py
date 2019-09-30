#ARC057
# https://beta.atcoder.jp/contests/arc057/submissions/2075056
import sys
input = sys.stdin.readline
N,K=map(int,input().split())
A=[int(input()) for i in range(N)]


if sum(A)==K:
    print(1)
    exit(0)

inf = 10**18
dp=[inf]*(N+1)
dp[0]=0
asum=0

for i in range(N):
    a=A[i]
    for j in range(N-1,-1,-1):
        if dp[j]==inf:
            continue
        k=(a*dp[j]//asum + 1) if asum else 1
        if k<=a:
            dp[j+1]=min(dp[j+1],dp[j]+k)
    asum+=a

if sum(A)!=K:
    print(sum(x <= K for x in dp)-1)