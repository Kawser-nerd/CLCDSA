from collections import deque

n = int(input())
a, b = map(lambda x: int(x) - 1, input().split())
m = int(input())
edges = [[] for _ in range(n)]
mod = 10**9 + 7


# ????????
for _ in range(m):
    i, j = map(int, input().split())
    edges[i-1].append(j-1)
    edges[j-1].append(i-1)


# q : ??????????????<-- [???] <--?
q = deque([a])
# dist : ?????????????
INF = float("inf")
dist = [INF] * n
dist[a] = 0
# ptn : ?????????????????????
ptn = [0] * n
ptn[a] = 1

while q:
    v = q.popleft()
    for town in edges[v]:
        if dist[v]+1 < dist[town]:
            dist[town] = dist[v]+1
            ptn[town] = ptn[v]  # v ???????1???????? v ????????????
            q.append(town)
        elif dist[v]+1 == dist[town]:
            ptn[town] += ptn[v]

print(ptn[b] % mod)