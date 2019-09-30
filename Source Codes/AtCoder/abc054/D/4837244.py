def mixing_experiment(N: int, Ma: int, Mb: int, drags: list)->int:
    INF = float('inf')

    max_A = min(100, N * max(a for a, _, _ in drags))
    max_B = min(100, N * max(b for _, b, _ in drags))

    dp = [[INF] * (max_B+1) for _ in range(max_A+1)]
    dp[0][0] = 0

    for (a, b, c) in drags:
        for ca in range(max_A-a, -1, -1):
            for cb in range(max_B-b, -1, -1):
                dp[ca+a][cb+b] = \
                    min(dp[ca+a][cb+b], dp[ca][cb] + c)
        dp[a][b] = min(dp[a][b], c)

    ans = INF
    for ca in range(1, max_A+1):
        for cb in range(1, max_B+1):
            if ca * Mb != cb * Ma:
                continue
            ans = min(ans, dp[ca][cb])

    return ans if 0 < ans and ans < INF else -1


if __name__ == "__main__":
    N = 0
    N, Ma, Mb = map(int, input().split())
    drags = [tuple(int(s) for s in input().split()) for _ in range(N)]
    ans = mixing_experiment(N, Ma, Mb, drags)
    print(ans)