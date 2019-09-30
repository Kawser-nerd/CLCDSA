from collections import deque
import sys
readline = sys.stdin.readline

N, M = map(int, readline().split())
G = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, readline().split())
    a -= 1; b -= 1
    G[a].append(b)
    G[b].append(a)

def check(s, t):
    u = [0]*N
    u[s] = u[t] = 1
    que = deque()
    for v in G[s]:
        if v == t:
            continue
        u[v] = 1
        que.append(v)
        ok = 0
        while que:
            x = que.popleft()
            for y in G[x]:
                if y == s and x != v:
                    return 1
                if not u[y]:
                    u[y] = 1
                    que.append(y)
    return 0
C = [0]*4
ok = 1
for i in range(N):
    if len(G[i]) % 2 == 1:
        ok = 0
    C[min(3, len(G[i])//2)] += 1
if C[1] == N or (C[1] == N-1 and C[2] == 1):
    ok = 0
elif C[1] == N-2 and C[2] == 2:
    VV = []
    for i in range(N):
        if len(G[i]) == 4:
            VV.append(i)
    if not check(*VV):
        ok = 0
print("Yes" if ok else "No")