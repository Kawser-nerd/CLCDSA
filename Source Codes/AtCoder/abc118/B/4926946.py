n, m = map(int, input().split())

cnt = [0 for i in range(m)]
for i in range(n):
    a = list(map(int, input().split()))
    for j in range(a[0]):
        cnt[a[j + 1] - 1] += 1
ans = 0
for i in range(m):
    if cnt[i] == n:
        ans += 1
print(ans)