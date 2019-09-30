n, h = map(int, input().split())
a, b, c, d, e = map(int, input().split())
minc = a * n
for i in range(0, n + 1):
    j = max(0, (n * e - h - i * (b + e)) // (d + e) + 1)
    k = n - i - j
    minc = min(minc, a * i + c * j)
print(minc)