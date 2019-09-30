from heapq import *
n,m,cou=map(int, input().split())
cou -= 1
g = [[] for i in range(n)]
for k in range(m):
    a,b = map(int, input().split())
    a -= 1; b -= 1;
    g[a].append(b)
    g[b].append(a)
lis = []
ds=[0]*n
heappush(lis, (-cou,cou))
ds[cou] = cou
while len(lis):
    w,b = heappop(lis)
    w = -w
    if b < w or ds[b] > w:continue
    for e in g[b]:
        np = min(w,e)
        if ds[e] >= np:continue
        ds[e] = np
        heappush(lis, (-np,e))
for x in [i+1 for i in range(n) if ds[i] >= i]:print(x)