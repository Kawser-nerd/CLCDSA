# coding: utf-8
N, K = map(int, input().split())
T = [list(map(int, input().split())) for _ in range(N)]
def dfs(q, v):
    if q == N:
        return v == 0
    for i in range(K):
        if dfs(q + 1, v^T[q][i]):
            return True
    return False
print(['Nothing', 'Found'][dfs(0, 0)])