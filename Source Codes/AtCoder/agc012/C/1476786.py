#!/usr/bin/env python3
n = int(input())
x = []
y = []
k = 1
for c in bin(n + 1)[2 :][1 :]:
    x += [ k ]
    y += [ k ]
    k += 1
    if int(c):
        x = [ k ] + x
        y += [ k ]
        k += 1
print(len(x + y))
print(*(x + y))