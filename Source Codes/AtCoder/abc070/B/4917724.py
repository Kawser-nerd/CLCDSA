import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

a, b, c, d = nm()

if b <= c or d <= a:
    print(0)
else:
    print(min(b, d) - max(a, c))