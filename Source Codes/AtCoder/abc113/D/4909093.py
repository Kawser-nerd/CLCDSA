h, w, k = map(int, input().split())
M = 1000000007
x = [ 0 for i in range(w)]
x[0] = 1
for i in range(1, w):
    for j in range((1<<i)):
        f = 0
        for l in range(i-1):
            if ((j>>l)&1) == 1 and ((j>>(l+1))&1) == 1:
                f = 1
                break
        if f == 0:
            x[i] += 1
    x[i] %= M
    #print(x[i])

def g(a):
    if a < 0: return 1
    return x[a]

dp = [[0 for j in range(w)] for i in range(h+1)]
dp[0][0] = 1
for i in range(1, h+1):
    for j in range(w):
        dp[i][j]  = dp[i-1][j]   * g(j-1) * g(w-j-2)
        if j-1 >= 0:dp[i][j] += dp[i-1][j-1] * g(j-2) * g(w-j-2)
        if j+1 <  w:dp[i][j] += dp[i-1][j+1] * g(j-1) * g(w-j-3)
        dp[i][j] %= M
        #print(i, j, dp[i][j])

print(dp[h][k-1])