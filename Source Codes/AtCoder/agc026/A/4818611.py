n = int(input())
a = list(map(int, input().split()))
l = r = 0
ans = 0
while l < n:
    while r < n and a[l] == a[r]:
        r += 1
    k = r - l
    if k > 1:
        ans += k // 2
    l = r
print(ans)