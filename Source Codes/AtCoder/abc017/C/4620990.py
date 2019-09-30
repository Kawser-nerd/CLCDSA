N,M=map(int,input().split())
from collections import defaultdict
L=defaultdict(int)
R=defaultdict(int)
S=0
for i in range(N):
    l,r,s=map(int,input().split())
    L[l]+=s
    R[r]+=s
    S+=s
now=L[1]
ans=now
for i in range(2,1+M):
    now=now+L[i]-R[i-1]
    ans=min(ans,now)
print(S-ans)