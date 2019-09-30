#13
n, x = map(int, input().split())
a = list(map(int, input().split()))
i = 0
ans = 0
while x>0:
    if x%2 == 1:
        ans += a[i]
    i += 1
    x = x//2
print(ans)