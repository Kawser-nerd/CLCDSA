# -*- coding: utf-8 -*-
n,a,b = map(int, input().split())
x = [int(i) for i in input().split()]

ret = 0
for i in range(n-1):
    if (x[i+1]-x[i])*a>=b:
        ret += b
    else:
        ret += (x[i+1]-x[i])*a
print(ret)