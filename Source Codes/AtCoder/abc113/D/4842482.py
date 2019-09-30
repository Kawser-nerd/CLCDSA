from itertools import product

mod = 1000000007
H, W, K = map(int, input().split())
dp = {}
dp[0] = [1] + [0]*(W-1)

for h in range(1, H+1):
    dp[h] = [0] * W
    for pattern in product([0, 1], repeat=W-1):
        c = 0
        for p in pattern:            
            c = ((c + 1) if p == 1 else 0)
            if c >= 2:
                break            
        if c >= 2:
            continue
        for i in range(0, W):
            if i <= W-2 and pattern[i] == 1:
                dp[h][i] = (dp[h][i] + dp[h-1][i+1]) % mod
            elif i >= 1 and pattern[i-1] == 1:
                dp[h][i] = (dp[h][i] + dp[h-1][i-1]) % mod
            else:
                dp[h][i] = (dp[h][i] + dp[h-1][i]) % mod
print(dp[H][K-1])