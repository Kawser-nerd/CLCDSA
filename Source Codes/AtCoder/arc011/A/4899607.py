m, n, N = [int(_) for _ in input().split()]

result = N
s = N

while s >= m:
    x, s = divmod(s, m)
    s += x * n
    result += x * n

print(result)