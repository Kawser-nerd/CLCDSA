n = int(input())
a = [int(input()) for _ in range(n)]
ans = 0
l = r = 0
while l < n:
    s = 0
    while r < n and a[r] > 0:
        s += a[r]
        r += 1
    ans += s // 2
    l = r + 1
    r = l
print(ans)