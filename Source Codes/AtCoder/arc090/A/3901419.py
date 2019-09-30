N = int(input())
a = [[]]+[[0]+list(map(int, input().split())) for _ in [0]*2]
dp = [[0]*(N+1) for _ in [0]*3]

for y in range(1, 3):
    for x in range(1, N+1):
        dp[y][x] = max(dp[y-1][x], dp[y][x-1]) + a[y][x]

print(dp[-1][-1])