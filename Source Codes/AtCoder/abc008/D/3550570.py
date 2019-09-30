W, H = map(int, input().split())
N = int(input())
X, Y = [], []
dp = {}
for i in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)


def calc(l, r, b, t):
    if l > r or b > t:
        return 0

    q = (l, r, b, t)
    if q in dp:
        return dp[q]

    tmp = 0
    for i in range(N):
        if l <= X[i] <= r and b <= Y[i] <= t:
            tmp = max(tmp, r - l + t - b + 1 + calc(X[i] + 1, r, Y[i] + 1, t)
                      + calc(X[i] + 1, r, b, Y[i] - 1) + calc(l, X[i] - 1, Y[i] + 1, t)
                      + calc(l, X[i] - 1, b, Y[i] - 1))

    dp[q] = tmp

    return dp[q]


print(calc(1, W, 1, H))