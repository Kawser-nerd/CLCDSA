N, W = map(int, input().split())
MAX_N = 100


def main():
    w, v = [], []
    for i in range(N):
        wi, vi = map(int, input().split())
        w.append(wi)
        v.append(vi)

    dp = [[[0 for k in range(3*MAX_N+1)] for j in range(N+1)] for i in range(N+1)]
    for i in range(1, N+1):
        for j in range(1, i+1):
            for k in range(3*j+1):
                if k - (w[i-1]-w[0]) >= 0:
                    if j * w[0] + k <= W and j > 0:
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-1][k-(w[i-1]-w[0])]+v[i-1])
                    else:
                        dp[i][j][k] = 0
                else:
                    dp[i][j][k] = dp[i-1][j][k]

    ans = 0
    for i in range(N+1):
        for j in range(3*i+1):
            ans = max(ans, dp[N][i][j])

    print(ans)


if __name__ == '__main__':
    main()