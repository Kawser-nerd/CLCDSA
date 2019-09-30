import copy

N, K = (int(i) for i in input().split())

G = [[] for i in range(N)]
E = []
for i in range(N-1):
    A, B = (int(i) for i in input().split())
    E.append((A-1, B-1))
    G[A-1].append(B-1)
    G[B-1].append(A-1)

def DFS(u, n, G):
    q = [u]
    v = [0]*N
    d = [0]*N
    while q:
        u1 = q.pop()
        v[u1] = 1
        if d[u1] < n:
            for u2 in G[u1]:
                if not v[u2]:
                    d[u2] = d[u1] + 1
                    q.append(u2)
    return sum(v)

def DFS_E(u, uu, n, G):
    q = [u, uu]
    v = [0]*N
    d = [0]*N
    while q:
        u1 = q.pop()
        v[u1] = 1
        if d[u1] < n:
            for u2 in G[u1]:
                if not v[u2] and u2 != u:
                    d[u2] = d[u1] + 1
                    q.append(u2)
    return sum(v)


if K % 2 == 0:
    ans = 0
    for v in range(N):
        ans = max(ans, DFS(v, K//2, G))
    print(N-ans)
else:
    ans = 0
    for u, v in E:
        ans = max(ans, DFS_E(u,v,(K-1)//2,G))
    print(N-ans)