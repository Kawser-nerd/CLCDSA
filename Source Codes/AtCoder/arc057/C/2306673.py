# -*- coding:utf-8 -*-
N = int(input())

A = N ** 2
B = (N + 1) ** 2

P = 1
ans = 1
while True:
    if A <= A//P*P < B:
        ans = A//P
    elif A <= (A+P-1)//P*P < B:
        ans = (A+P-1)//P
    else:
        break
    P *= 100

print(ans)