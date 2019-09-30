T = int(input())

for tc in range(T):
    E, R, N = map(int, input().split())
    v = list(map(int, input().split()))

    gainz = 0
    e = E
    for i in range(N):
        spend = e
        for j in range(i, N):
            if v[j] > v[i]:
                spend = min(spend, e + R * (j - i) - E)
        spend = max(spend, 0)
        e -= spend
        e = min(e + R, E)
        gainz += v[i] * spend

    print("Case #{}: {}".format(tc + 1, gainz))
