import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

n = ni()
a = nl()
p1 = 0
p2 = 0
p3 = 0
for i in range(n):
    if a[i] % 2 == 0:
        if a[i] % 4 == 0:
            p3 += 1
        else:
            p2 += 1
    else:
        p1 += 1
if p1 <= p3:
    print('Yes')
else:
    if p1 == p3 + 1 and p2 == 0:
        print('Yes')
    else:
        print('No')