N,Ma,Mb=map(int,input().split())
medic=[tuple(map(int,input().split())) for _ in range(N)]
from collections import defaultdict
inf = float('inf')
dp=defaultdict(lambda :inf)
dp[(0,0)]=0
for n in range(N):
    dpc=dp.copy()
    a,b,c=medic[n]
    for d,cost in dpc.items():
        da,db=d
        dp[(da+a,db+b)]=min(dp[(da+a,db+b)],c+cost)
ans=inf
nowa,nowb=Ma,Mb
while nowa<=400 and nowb<=400:
    ans=min(ans,dp[nowa,nowb])
    nowa+=Ma
    nowb+=Mb
if ans>4000:ans=-1
print(ans)