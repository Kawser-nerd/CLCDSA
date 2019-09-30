n = int(input())
ans = 100000
for i in range(1, n+1):
    a = n // i
    b = abs(i - a) + (n - i * a)
    if b < ans:
        ans = b
print(ans)