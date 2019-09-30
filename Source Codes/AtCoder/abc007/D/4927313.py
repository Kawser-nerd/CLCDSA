from itertools import product

a, b = input().split()

def cnt(c:str):
    n = len(c)
    dp = [[[0]*2 for i in range(2)] for j in range(n+1)]
    dp[0][1][0] = 1
    for i, j, k in product(range(n), range(2), range(2)):
        max_n = int(c[i]) if j else 9
        for n in range(max_n+1):
            dp[i+1][j and n == max_n][k or n == 4 or n == 9] += dp[i][j][k]
    res = 0
    for i in range(2):
        res += dp[-1][i][1]
    return res
print(cnt(b) - cnt(str(int(a)-1)))