from heapq import heappush, heappop
readline = open(0).readline
N, M, S = map(int, readline().split())
G = [[] for i in range(N)]
for i in range(M):
    v, w = map(int, readline().split())
    G[v-1].append(w-1)
    G[w-1].append(v-1)

que = [1-S]
cost = [-1]*N
cost[S-1] = S-1
ans = []
while que:
    v = -heappop(que)
    c = cost[v]
    if v <= c:
        ans.append(v+1)
    for w in G[v]:
        if cost[w] != -1:
            continue
        heappush(que, -w)
        cost[w] = min(c, w)
ans.sort()
open(1, 'w').writelines(map("{}\n".format, ans))