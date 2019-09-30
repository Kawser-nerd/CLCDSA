# -*- coding: utf-8 -*-

d, n = map(int, input().split())

if d == 0 and n == 100:
    print(101)
elif d == 0:
    print(n)

if d == 1 and n == 100:
    print(10100)
elif d == 1:
    print(100 * n)

if d == 2 and n == 100:
    print(1010000)
elif d == 2:
    print(10000 * n)