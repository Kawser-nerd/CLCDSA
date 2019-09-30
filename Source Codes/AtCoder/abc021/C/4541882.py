mod = 10 ** 9 + 7
n = int(input())
a, b = map(int, input().split())
m = int(input())
inf = float('inf')

G = [[inf] * n for i in range(n)]
for i in range(n):
    G[i][i] = 0
for i in range(m):
    x, y = map(int, input().split())
    G[x - 1][y - 1] = 1
    G[y - 1][x - 1] = 1
    
def wf(G):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                G[i][j] = min(G[i][j], G[i][k] + G[k][j])

wf(G)

dp = [0] * n
dp[a - 1] = 1
for i in range(n):
    for j in range(n):
        if G[a - 1][j] != i:
            continue
        for k in range(n):
            if G[a - 1][k] == i + 1 and G[j][k] == 1:
                dp[k] = (dp[j] + dp[k]) % mod
                
print(dp[b - 1])