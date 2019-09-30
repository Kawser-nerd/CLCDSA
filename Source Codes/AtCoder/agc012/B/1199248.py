from collections import defaultdict

def paint(v, d, c):
    if color[v] == 0:
        color[v] = c
    if dp[v] >= d or d == 0:
        return
    dp[v] = d
    for nb in graph[v]:
        paint(nb, d-1, c)

N, M = map(int, input().split())
dp = [0] * N
color = [0] * N
graph = defaultdict(set)
for _ in range(M):
    i, j = map(int, input().split())
    graph[i-1].add(j-1)
    graph[j-1].add(i-1)
Q = int(input())
vdcs = []
for _ in range(Q):
    v, d, c = map(int, input().split())
    vdcs.append((v-1, d, c))
vdcs.reverse()

for v, d, c in vdcs:
    paint(v, d, c)

for c in color:
    print(c)