import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

n, m = nm()
ab = [nl() for i in range(m)]
ans = [0 for i in range(n)]
for i in range(m):
    ans[ab[i][0] - 1] += 1
    ans[ab[i][1] - 1] += 1
for i in range(n):
    print(ans[i])