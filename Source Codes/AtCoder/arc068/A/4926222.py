import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

x = ni()
if x % 11 == 0:
    print(x // 11 * 2)
else:
    if x % 11 <= 6:
        print(x // 11 * 2 + 1)
    else:
        print(x // 11 * 2 + 2)