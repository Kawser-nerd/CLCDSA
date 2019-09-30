import sys
import heapq
sys.setrecursionlimit(2*10**5)
N=int(input())
a=[-1]+[int(input())-1 for i in range(1,N)]
G=[[] for i in range(N)]
for i in range(1,N):
    G[a[i]].append(i)
def dp(i):
    if len(G[i])==0:
        return 0
    q=[]
    for j in G[i]:
        heapq.heappush(q,-dp(j))
    k=1
    res=0
    while(q):
        x=-heapq.heappop(q)
        res=max(res,x+k)
        k+=1
    return res
print(dp(0))