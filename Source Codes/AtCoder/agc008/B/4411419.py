import sys
input=sys.stdin.readline
from itertools import accumulate
n,k=map(int,input().split())
A=list(map(int,input().split()))
SA=[0]+list(accumulate(A))
B=[]
for a in A:
    B.append(max(0,a))
SB=[0]+list(accumulate(B))
SB.append(SB[-1])
ans=0
for i in range(n-k+1):
    ans=max(ans,SB[i]+SA[i+k]-SA[i]+SB[n]-SB[i+k])
    ans=max(ans,SB[i]+SB[n]-SB[i+k])
print(ans)