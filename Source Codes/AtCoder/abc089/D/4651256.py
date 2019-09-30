def main():
    H, W, D = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(H)]
    Q = int(input())
    ans = []

    x = [0 for _ in range(90001)]
    y = [0 for _ in range(90001)]
    dp = [0 for _ in range(90001)]

    for i, row in enumerate(A):
        for j, a in enumerate(row):
            x[a] = j
            y[a] = i
    for i in range(D + 1, H * W + 1):
        dp[i] = dp[i - D] + abs(x[i] - x[i - D]) + abs(y[i] - y[i - D])

    for _ in range(Q):
        L, R = map(int, input().split())
        ans.append(dp[R] - dp[L])
    for a in ans:
        print(a)


main()