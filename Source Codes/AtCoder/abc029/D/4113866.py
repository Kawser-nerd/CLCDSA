N = int(input())
ans = 0

k = 10
while k <= N * 10:
    A = (N // k) * (k // 10)
    rest = N % k
    B = 0
    if rest >= 2 * k // 10:
        B = k // 10

    elif rest >= k // 10:
        B = rest % (k // 10) + 1

    ans += (A + B)
    k *= 10

print(ans)