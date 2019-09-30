inf = 9999999999
N, Ma, Mb = map(int, input().split())
d = [{} for i in range(N + 1)]
for i in range(N):
    a, b, c = map(int, input().split())
    for (j, k) in d[i]:
        d[i + 1][j, k] = d[i][j, k]
    d[i + 1][a, b] = min(c, d[i].get((a, b), inf))
    for (j, k) in d[i]:
        d[i + 1][j + a, k + b] = min(d[i][j, k] + c, d[i].get((j + a, k + b), inf))
ans = inf
for (j, k) in d[N]:
    if j * Mb == k * Ma:
        ans = min(ans, d[N][j, k])
if ans == inf:
    ans = -1
print(ans)