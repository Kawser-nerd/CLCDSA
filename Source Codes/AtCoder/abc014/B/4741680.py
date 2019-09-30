n, x = map(int, input().split())
a = list(map(int, input().split()))
ans = 0

for i in range(n):
    if x % 2 == 1:
        ans += a[i]
    x = x//2

print(ans)