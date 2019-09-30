import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

n = ni()
a = nl()
c = collections.Counter(a)

key = list(c.keys())
key.sort(reverse=True)
count = 0
for i in range(len(key)):
    if c[key[i]] >= 4 and count != 1:
        print(key[i] ** 2)
        exit()
    if c[key[i]] >= 2:
        if count == 0:
            a = key[i]
            count += 1
        elif count == 1:
            b = key[i]
            count += 1
    if count >= 2:
        print(a * b)
        exit()
print(0)