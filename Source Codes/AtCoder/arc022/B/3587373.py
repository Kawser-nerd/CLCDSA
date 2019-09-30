# coding:utf-8

import sys


input = sys.stdin.readline


def inpl(): return list(map(int, input().split()))


N = int(input())
A = inpl()

aji = set()
ans = 1
left, right = 0, 0
for left in range(N):
    while right < N and (A[right] not in aji):
        aji.add(A[right])
        right += 1

    ans = max(ans, right - left)

    if left == right:
        right += 1
    else:
        aji.remove(A[left])

print(ans)