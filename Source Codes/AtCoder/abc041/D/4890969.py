def running(N: int, M: int, queries: list)->int:
    PHI = 0

    g = [[0] * N for _ in range(N)]
    for u, v in queries:
        g[u-1][v-1] = 1
        g[v-1][u-1] = -1

    dp = [0 for _ in range(1 << N)]
    dp[PHI] = 1

    for S in range(1, 1 << N):
        for v in range(N):
            if S & (1 << v) == 0:
                # v not in S
                continue
            # S-{v}
            S_v = S & ~(1 << v)

            if any((S_v & (1 << k)) and g[k][v] == -1 for k in range(N)):
                # ??????
                continue

            dp[S] += dp[S_v]
    # print(dp)
    return dp[(1 << N) - 1]


if __name__ == "__main__":
    M = 0
    N, M = map(int, input().split())
    queries = [tuple(int(s) for s in input().split()) for _ in range(M)]
    ans = running(N, M, queries)
    print(ans)