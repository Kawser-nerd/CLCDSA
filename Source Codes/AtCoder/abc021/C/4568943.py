# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
MOD = 10**9+7


N = int(input())
s, g = map(lambda x: int(x)-1, input().split())
M = int(input())
adj = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    adj[a].append(b)
    adj[b].append(a)

depth = [-1]*N
path = [0]*N

Q = [[s, 0]]
path[s] = 1
depth[s] = 0
while Q:
    n, d = Q.pop(0)
    if adj[n]:
        for c in adj[n]:
            if depth[c] == -1:
                depth[c] = d
                path[c] += path[n] % MOD
                Q.append([c, d+1])
            elif depth[c] == d:
                path[c] += path[n] % MOD
            else:
                continue
print(path[g] % MOD)