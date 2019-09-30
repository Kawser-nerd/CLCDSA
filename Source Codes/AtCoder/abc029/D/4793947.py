# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
N = input()[:-1]

dp = [[[0]*(len(N)+1) for _ in range(2)] for _ in range(len(N)+1)]

dp[0][0][0] = 1

for i in range(len(N)):
    for j in range(2):
        for k in range(len(N)):
            if dp[i][j][k] == 0:
                continue
            elif j == 1:  # N?????
                dp[i+1][1][k+1] += dp[i][j][k]
                dp[i+1][1][k] += dp[i][j][k]*9
            else:
                if N[i] == '1':
                    dp[i+1][0][k+1] += dp[i][j][k]
                    dp[i+1][1][k] += dp[i][j][k]
                elif N[i] == '0':
                    dp[i+1][0][k] += dp[i][j][k]
                else:
                    dp[i+1][0][k] = dp[i][j][k]
                    dp[i+1][1][k] = dp[i][j][k]*(int(N[i])-1)
                    dp[i+1][1][k+1] += dp[i][j][k]

ans = 0
for j in range(2):
    for k in range(len(N)+1):
        if dp[len(N)][j][k]:
            ans += k*dp[len(N)][j][k]
print(ans)