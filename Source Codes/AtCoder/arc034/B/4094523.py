#!/usr/bin/env python3


def f(x):
    res = 0
    while x > 0:
        res += x % 10
        x //= 10
    return res


N = int(input())
ans = []
for i in range(N)[-154:]:
    j = i + 1
    if j + f(j) == N:
        ans.append(j)

print(len(ans))
for x in ans:
    print(x)