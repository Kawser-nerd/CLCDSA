N, X = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
for i in range(N):
    if ((X >> i) & 1) == 1:
        ans += a[i]
print(ans)