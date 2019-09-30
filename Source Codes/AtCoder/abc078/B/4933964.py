X, Y, Z = map(int, input().split())

n = 0
ans = 0
while n <= X:
    if Y * n + (1 + n) * Z <= X:
        ans = n
    n += 1
print(ans)