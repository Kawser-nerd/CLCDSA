n, m = map(int, input().split())
print((m * 1900 + (n - m) * 100) * (2 ** m))