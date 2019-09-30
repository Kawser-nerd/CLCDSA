#ARC057
import sys
input = sys.stdin.readline
N,K=map(int,input().split())
A=[int(input()) for i in range(N)]

if sum(A)==K:
    print(1)
    exit(0)
big=K+1
dp=[big]*(N+1) 
dp[0]=0
dp[1]=1
asum=A[0]

for i in range(2,1+N):
    a=A[i-1]
    dpc=dp.copy()
    for j in range(1,1+i):
        k=a*dpc[j-1]//asum +1
        if k<=a:dp[j]=min(dpc[j-1]+k,dp[j])
    asum+=a


if sum(A)!=K:
    ans=0
    for x in dp:
        if x<=K:ans+=1
    print(ans-1)