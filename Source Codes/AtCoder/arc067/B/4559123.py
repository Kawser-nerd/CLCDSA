n, a, b = map(int, input().split())
x = list(map(int, input().split()))
uf = [1]*n
ans = 0
for i in range(n-1):
    if a*(x[i+1]-x[i]) <= b:
        ans += a*(x[i+1]-x[i])
        uf[i+1] = 0
ans += b*(sum(uf)-1)
print(ans)