# seishin.py
from collections import deque
N, K = map(int, input().split())
G = [[] for i in range(N)]
E = []
for i in range(N-1):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
    E.append((a-1, b-1))

def bfs0(s):
    que = deque()
    prev = [-1]*N
    prev[s] = s
    que.append(s)
    while que:
        v = que.popleft()
        for w in G[v]:
            if prev[w] == -1:
                prev[w] = v
                que.append(w)
    L = []
    while v != s:
        L.append(v)
        v = prev[v]
    L.append(s)
    return L

D = bfs0(0)
D = bfs0(D[0])

C = {e for e in D}

l = len(D)
if l <= K+1:
    print(0)
    exit(0)

def bfs(que, U, K2):
    if K2 == 0:
        return 0
    cnt = 0
    while que:
        v = que.popleft()
        for w in G[v]:
            if U[w] != -1:
                continue
            U[w] = r = U[v] + 1
            cnt += 1
            if r < K2:
                que.append(w)
    return cnt

ans = 0
que = deque()
if K % 2:
    for a, b in E:
        U = [-1]*N
        U[a] = U[b] = 0
        que.append(a)
        que.append(b)
        ans = max(ans, bfs(que, U, K // 2) + 2)
else:
    for i in range(N):
        U = [-1]*N
        U[i] = 0
        que.append(i)
        ans = max(ans, bfs(que, U, K // 2) + 1)
print(N - ans)