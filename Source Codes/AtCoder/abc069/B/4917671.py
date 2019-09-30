import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

s = ns()
print(s[0] + str(len(s) - 2) + s[-1])