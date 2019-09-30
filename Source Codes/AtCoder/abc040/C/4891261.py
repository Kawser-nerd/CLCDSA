def poll_poll_poll_poll_poll(N: int, A: list)->int:
    dp = [float('inf')] * N
    dp[0] = 0

    for i in range(1, N):
        dp[i] = dp[i-1] + abs(A[i] - A[i-1])
        if i > 1:
            dp[i] = min(dp[i], dp[i-2] + abs(A[i] - A[i-2]))

    return dp[N-1]


if __name__ == "__main__":
    N = int(input())
    A = [int(s) for s in input().split()]
    ans = poll_poll_poll_poll_poll(N, A)
    print(ans)