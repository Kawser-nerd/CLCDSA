n, h = map(int, input().split())
a, b, c, d, e = map(int, input().split())

ans = float("inf")
for i in range(n + 1):
    j = max(0, ((n * e - h) - (b + e) * i) // (d + e) + 1)
    cost = i * a + j * c
    if (0 <= j <= n) and (ans > cost):
        ans = cost

print(ans)