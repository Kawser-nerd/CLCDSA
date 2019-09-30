# -*- coding: utf-8 -*-
def inpl(): return list(map(int, input().split()))
N = int(input())
B = ["." for i in range(9)]
for _ in range(N):
    L = input()
    for i in range(9):
      B[i] += L[i]

ans = 0
for i in range(9):
    ans += B[i].count("x") + B[i].count(".o")+ B[i].count("xo")
print(ans)