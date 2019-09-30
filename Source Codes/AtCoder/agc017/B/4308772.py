n, a, b, c, d = map(int, input().split())
for m in range(n):
    if c * (n - 1 - m) - d * m <= b - a <= -c * m + (n - 1 - m) * d:
        print("YES")
        exit()

print("NO")