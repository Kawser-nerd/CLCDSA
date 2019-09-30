# coding:utf-8

import sys

input = sys.stdin.readline


def inpl(): return list(map(int, input().split()))


K = int(input())
N = int(input())
src = []
for _ in range(N):
    src.append(inpl())


def solve(price):
    n = 0
    for a, d in src:
        if price < a:
            continue
        n += (price - a) // d + 1

    if n >= K:
        return True
    else:
        return False


left, right = 0, 10 ** 12
while left + 1 < right:
    mid = (left + right) // 2
    if solve(mid):
        right = mid
    else:
        left = mid

ans = 0
used = 0
t = right
for a, d in src:
    if t < a:
        continue
    x = (t - a) // d + 1
    used += x
    ans += x * a + d * x * (x - 1) // 2

print(ans - (used - K) * t)