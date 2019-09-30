n, m = map(int, input().split())
a = [list(map(int, input().split()))[1:] for i in range(n)]

ans = 0
for x in range(m):
    count = 0
    for i in range(n):
        if x + 1 in a[i]:
            count += 1
    if count == n:
        ans += 1
print(ans)