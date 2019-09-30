#!/usr/bin/env python3
N = int(input())
h = [int(input()) for _ in range(N)]
ans = 0
for t in range(N):
    if t > 0 and h[t - 1] >= h[t]:
        continue
    if t < N - 1 and h[t] <= h[t + 1]:
        continue
    s = t
    while s > 0 and h[s - 1] < h[s]:
        s -= 1
    u = t
    while u < N - 1 and h[u] > h[u + 1]:
        u += 1
    ans = max(ans, u - s + 1)
print(ans)