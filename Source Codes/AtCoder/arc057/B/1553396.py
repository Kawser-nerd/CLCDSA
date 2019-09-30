from math import ceil
N, K = map(int, input().split())
a = [int(input()) for _ in [None]*N]

if K == 0:
    print(0)
elif N == 1 or sum(a) == K:
    print(1)
else:
    inf = float("inf")
    dp = [inf]*((N-1)*N)
    dp[0] = 0
    dp[1] = 1
    result = 1
    old_total = a[0]

    for i in range(1, N-1):
        new_total = old_total + a[i]
        m = new_total / old_total
        next_max = i*N+result
        next_min = max(next_max-(N-2-i+1), i*N)

        for j in range(next_max, next_min-1, -1):
            n = dp[j-N]
            v = ceil(m * n + 0.000000001)

            if dp[j] > n:
                dp[j] = n
            if v <= new_total and v <= K and dp[j+1] > v:
                dp[j+1] = v
                if j == next_max:
                    result += 1

        old_total = new_total

    last = dp[(N-2)*N+result]
    new_total = old_total + a[N-1]
    m = new_total / old_total
    v = ceil(m*last+0.000000001)
    if v <= new_total and v <= K:
        result += 1

    print(result)