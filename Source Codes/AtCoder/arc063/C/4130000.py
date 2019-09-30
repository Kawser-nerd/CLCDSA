from collections import deque
import sys
sys.setrecursionlimit(int(1e7))

def inpl(): return list(map(int, input().split()))

N = int(input())
G = [[] for _ in range(N+1)]

X = [-1 for _ in range(N+1)] # is odd
U = [1e7 for _ in range(N+1)]
L = [-1e7 for _ in range(N+1)]

for _ in range(N-1):
    a, b = inpl()
    G[a].append(b)
    G[b].append(a)

K = int(input())
for _ in range(K):
    v, p = inpl()
    U[v], L[v], X[v] = p, p, p%2

searched = [0]*(N+1)

def dfs(u, l, x, i):
    searched[i] = True
    if X[i] >= 0 and X[i] != x:
        X[i] = 2
        return -1e7, 1e7
    U[i] = min(U[i], u)
    L[i] = max(L[i], l)
    X[i] = x

    for j in G[i]:
        if searched[j]:
            continue
        nu, nl = dfs(U[i]+1, L[i]-1, (X[i]+1)%2, j)
        U[i] = min(U[i], nu+1)
        L[i] = max(L[i], nl-1)
    return U[i], L[i]

dfs(U[v], L[v], X[v], v)

Q = [v]
searched = [0]*(N+1)
answer = [0]*(N+1)
answer[v] = U[v] 
OK = True

if max(X) == 2:
    OK = False
    Q = []

while Q:
    p = Q.pop()
    for q in G[p]:
        if searched[q]:
            continue
        searched[q] = True
        Q.append(q)
        if L[q] <= answer[p] + 1 <= U[q]:
            answer[q] = answer[p] + 1
        elif L[q] <= answer[p] - 1 <= U[q]:
            answer[q] = answer[p] - 1
        else:
            OK = False
            Q = []
            break
if OK:
    print("Yes")
    print(*answer[1:], sep="\n")
else:
    print("No")