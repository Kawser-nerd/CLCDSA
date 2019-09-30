import sys
sys.setrecursionlimit(10**6)

n = int(input())
abc = [[int(item) for item in input().split()] for _ in range(n-1)]
q, k = [int(item) for item in input().split()]
xy = [[int(item) for item in input().split()] for _ in range(q)]

distance = [0] * n
e = [[] for _ in range(n)]
w = [[] for _ in range(n)]
for a, b, c in abc:
    e[a-1].append(b-1)
    e[b-1].append(a-1)
    w[a-1].append(c)
    w[b-1].append(c)

def dfs(v, par, dist):
    distance[v] = dist
    if len(e[v]) == 0:
        return True
    for i in range(len(e[v])):
        if e[v][i] == par:
            continue
        dfs(e[v][i], v, dist + w[v][i])

dfs(k-1, -1, 0)
for x, y in xy:
    print(distance[x-1] + distance[y-1])