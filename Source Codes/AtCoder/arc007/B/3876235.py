#!/usr/bin/env python3
N, M = map(int, input().split())
disk = [int(input()) for _ in range(M)]
ans = [i for i in range(N + 1)]
for d in disk:
    for i in range(N + 1)[1:]:
        if ans[i] == d:
            ans[0], ans[i] = ans[i], ans[0]
for x in ans[1:]:
    print(x)