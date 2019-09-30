# coding: utf-8
N, M = map(int, input().split())
imos = [0] * (M + 1)
ans = 0
for _ in range(N):
    l, r, s = map(int, input().split())
    imos[l - 1] += s
    imos[r] -= s
    ans += s
for i in range(M):
    imos[i + 1] += imos[i]
print(ans - min(imos[:-1]))