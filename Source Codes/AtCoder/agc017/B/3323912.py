n, a, b, c, d = map(int, input().split())

dis = b - a
for i in range(n):
    if c * (n - i - 1) - d * i <= dis <= d * (n - i - 1) - c * i:
        print('YES')
        exit()

print('NO')