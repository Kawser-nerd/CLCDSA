#!/usr/bin/env python3
n, c = map(int, input().split())
a = [int(input()) for _ in range(n)]
ans = 1e7
for i in range(1, 11):
    for j in range(1, 11):
        if i == j:
            continue
        b = [[i, j][k % 2] for k in range(n)]
        cnt = sum([a[k] != b[k] for k in range(n)])
        ans = min(ans, cnt)
print(ans * c)