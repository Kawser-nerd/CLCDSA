A, B = map(int, input().split())
A = A - 1


def f(x):
    X = str(x)
    n = len(X)
    dp = [[[0] * 2 for _ in range(2)] for _ in range(n + 1)]

    dp[0][0][0] = 1
    for i in range(n):
        for j in range(2):
            for k in range(2):
                if j == 1:
                    d = 9
                else:
                    d = int(X[i])
                for e in range(d + 1):
                    dp[i + 1][j or e < d][k or e == 4 or e == 9] += dp[i][j][k]
    ans = 0
    for i in range(2):
        ans += dp[n][i][1]
    return ans


print(f(B) - f(A))