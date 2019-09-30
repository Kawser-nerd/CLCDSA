n, a, b = map(int, input().split())
print(max(n - 5, 0) * a + b * 5) if n >= 5 else print(n * b)