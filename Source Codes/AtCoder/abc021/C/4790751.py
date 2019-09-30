n = int(input())
a,b = [int(i)-1 for i in input().split()]
m = int(input())
INF = float('inf')
MOD = 10**9+7

G = [[INF]*n for i in range(n)]
for i in range(n):
    G[i][i] = 0
for i in range(m):
    x,y = [int(j)-1 for j in input().split()]
    G[x][y] = 1
    G[y][x] = 1
    
for k in range(n):
    for i in range(n):
        for j in range(n):
            G[i][j] = min(G[i][j],G[i][k]+G[k][j])

dp = [0]*n
dp[a] = 1
for i in range(n):
    for j in range(n):
        if G[a][j] != i:
            continue
        for k in range(n):
            if G[a][k] == i+1 and G[j][k] == 1:
                dp[k] = (dp[j]+dp[k])%MOD
                
print(dp[b])