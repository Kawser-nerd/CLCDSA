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
mod = 10 ** 9 + 7

val = list(c.values())
key = list(c.keys())
check = len(a) % 2
if check == 1:
    if val.count(1) != 1:
        print(0)
        exit()
    if key[val.index(1)] != 0:
        print(0)
        exit()
    else:
        if val.count(2) != len(val) - 1:
            print(0)
            exit()
        else:
            print(2 ** (val.count(2)) % mod)
else:
    if val.count(2) != len(val):
        print(0)
        exit()
    else:
        print(2 ** (len(val)) % mod)