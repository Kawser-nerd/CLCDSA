import sys
input=sys.stdin.readline
from itertools import accumulate
sys.setrecursionlimit(10**9)
mod=10**9+7
n=int(input())
A=list(map(int,input().split()))
S=list(accumulate([pow(i,mod-2,mod) for i in range(1,n+1)]))
ans=0
num=1
for i in range(2,n+1):
    num=num*i%mod
for i in range(n):
    ans+=A[i]*(S[i]+S[n-1-i]-1)%mod
ans=ans*num%mod
print(ans)