import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

n = ni()
ans = 0
for i in range(n):
    l, r = nm()
    ans += r - l + 1
print(ans)