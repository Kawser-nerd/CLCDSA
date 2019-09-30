#! /usr/bin/env python3

X = int(input())
L = X ** 2
R = (X+1) ** 2
P = 100
res = L

while True:
    if L <= L//P*P < R:
        res = L//P
    elif L <= (L+P-1)//P*P < R:
        res = (L+P-1)//P
    else:
        break

    P *= 100

print(res)