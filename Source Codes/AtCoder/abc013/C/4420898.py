n, h = map(int,input().split())
a, b, c, d, e = map(int,input().split())
res = 10**100
for x in range(n+1):
    y = max(0, ((n - x) * e - h - b * x) // (d + e) + 1)
    res = min(res, x * a + y * c)
print(res)