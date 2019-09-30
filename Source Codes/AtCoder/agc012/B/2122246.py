N, M = map(int, input().split())
G = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

dp = [{-1: -1} for i in range(N)]
mark = {}
Q = int(input())
col = [0]*(Q+1)
col[-1] = 0
C = []
for i in range(Q):
    v, d, c = map(int, input().split())
    col[i] = c
    C.append((v-1, d))

def dfs(v, d, idx):
    if d <= max(dp[v]):
        return
    dp[v][d] = idx
    if d:
        for w in G[v]:
            dfs(w, d-1, idx)

for i in range(Q-1, -1, -1):
    v, d = C[i]
    dfs(v, d, i)
print(*(col[max(e.values())] for e in dp), sep='\n')