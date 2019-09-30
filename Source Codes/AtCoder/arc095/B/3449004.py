# -*- coding: utf-8 -*-
n = int(input())
a = [int(x) for x in input().split()]

maxa = max(a)
mida = min(a)
for x in a:
    # print(x,mida,maxa//2-x)
    if abs(maxa//2 - x)<abs(maxa//2-mida):
        mida = x
print(maxa, mida)