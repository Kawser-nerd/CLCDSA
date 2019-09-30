from collections import deque
N = int(input())
G = [[] for i in range(N)]
for i in range(N - 1):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    G[a].append(b)
    G[b].append(a)

INF = float("inf")
d = [INF] * N
used = [False] * N
que = deque()
que.append(0)
d[0] = 0
ma = [0, 0]
while que:
    v = que.popleft()
    if used[v]:
        continue
    used[0] = True

    for w in G[v]:
        if d[w] > d[v] + 1:
            d[w] = d[v] + 1
            que.append(w)
            if d[w] > ma[0]:
                ma[0] = d[w]
                ma[1] = w

used = [False] * N
que = deque()
que.append(ma[1])
d = [INF] * N
d[ma[1]] = 0
ma2 = [0, ma[1]]
while que:
    v = que.popleft()
    if used[v]:
        continue
    used[v] = True

    for w in G[v]:
        if d[w] > d[v] + 1:
            d[w] = d[v] + 1
            que.append(w)
            if d[w] > ma2[0]:
                ma2[0] = d[w]
                ma2[1] = w

print(ma[1] + 1, ma2[1] + 1)