import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

n = ni()
a = nl()
l = [0 for _ in range(9)]
for i in range(n):
    if a[i] <= 399:
        l[0] += 1
    elif 400 <= a[i] <= 799:
        l[1] += 1
    elif 800 <= a[i] <= 1199:
        l[2] += 1
    elif 1200 <= a[i] <= 1599:
        l[3] += 1
    elif 1600 <= a[i] <= 1999:
        l[4] += 1
    elif 2000 <= a[i] <= 2399:
        l[5] += 1
    elif 2400 <= a[i] <= 2799:
        l[6] += 1
    elif 2800 <= a[i] <= 3199:
        l[7] += 1
    elif 3200 <= a[i]:
        l[8] += 1
if l[8] == 0:
    print(9 - l.count(0), 9 - l.count(0))
else:
    if l.count(0) == 8:
        print(1, l[8])
    else:
        print(8 - l.count(0), 8 - l.count(0) + l[8])