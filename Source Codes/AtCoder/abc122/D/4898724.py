n = int(input())

dp = [[[[0]*4 for k in range(4)] for j in range(4)] for i in range(n+1)]

dp[0][3][3][3] = 1
mod = 1000000007

for lens in range(n):
    for c1 in range(4):
        for c2 in range(4):
            for c3 in range(4):
                #print(lens,c1,c2,c3,dp[lens][c1][c2][c3])
                if dp[lens][c1][c2][c3] == 0:
                    continue
                for a in range(4):
                    if a == 2 and c1 == 1 and c2 == 0:
                        continue
                    if a == 2 and c1 == 0 and c2 == 1:
                        continue
                    if a == 1 and c1 == 2 and c2 == 0:
                        continue
                    if a == 2 and c1 == 1 and c3 == 0:
                        continue
                    if a == 2 and c2 == 1 and c3 == 0:
                        continue
                    dp[lens+1][a][c1][c2] += dp[lens][c1][c2][c3]
                    dp[lens+1][a][c1][c2] %= mod

ans = 0
for c1 in range(4):
    for c2 in range(4):
        for c3 in range(4):
            ans += dp[n][c1][c2][c3]
            ans %= mod

print(ans)