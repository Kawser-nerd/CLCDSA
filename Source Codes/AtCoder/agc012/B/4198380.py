import sys
from collections import deque
N, M = map(int, input().split())
edges = [[] for _ in [0]*N]
for a, b in (map(int, sys.stdin.readline().split()) for _ in [0]*M):
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)

Q = int(input())
queries = [list(map(int, l.split())) for l in sys.stdin][::-1]
dp = [-1]*N
color = [0]*N

dq = deque()
popleft, append, clear = dq.popleft, dq.append, dq.clear
for v, d, c in queries:
    if dp[v-1] >= d:
        continue
    dp[v-1] = d
    append((v-1, d))

    while dq:
        v, d = popleft()
        if not color[v]:
            color[v] = c
        d -= 1

        for dest in edges[v]:
            if dp[dest] >= d:
                continue
            dp[dest] = d
            append((dest, d))

print(*color, sep="\n")