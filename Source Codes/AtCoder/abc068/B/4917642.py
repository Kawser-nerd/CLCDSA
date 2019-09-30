import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

n = ni()

for i in range(n, -1, -1):
    if bin(i)[2:].count('1') == 1:
        print(i)
        exit()