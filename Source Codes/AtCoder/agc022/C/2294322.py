# -*- coding: utf-8 -*-
def inpl(): return tuple(map(int, input().split()))

N = int(input())
A = inpl()
B = inpl()
for a, b in zip(A, B):
    if a < b:
        print(-1)
        exit()
        
M = max(max(A), max(B))

S = [i for i in range(1, M+1)]
T = len(S)

def dfs(a, b, G):
    visited = [False]*(M+1)
    Q = [a]
    while Q:
        p = Q.pop()
        if visited[p]:
            continue
        else:
            visited[p] = True
            for q in G[p]:
                if q == b:
                    return True
                if not visited[q]:
                    Q.append(q)
    else:
        return False

found = False
for i in range(M, 0, -1):
    del S[S.index(i)]
    G = [set() for _ in range(M+1)]
    for j in range(1, M+1):
        for s in S:
            G[j].add(j%s)
    
    for a, b in zip(A, B):
        if a==b:
            continue
        if not dfs(a, b, G):
            S.append(i)
            break
    else:
        found = True

ans = 0
for s in S:
    ans += 2**s

if found:
    print(ans)
else:
    print(-1)