import numpy as np
MOD = 10**9+7
N = int(input())
a,b = map(lambda x:int(x)-1, input().split())
M = int(input())
adj = np.zeros((N,N))
for _ in range(M):
    x,y = map(lambda x:int(x)-1, input().split())
    adj[x][y] = adj[y][x] = 1
adj_ini = np.copy(adj)
while adj[a][b]==0:
    adj = np.dot(adj, adj_ini)
print(int(adj[a][b])%MOD)