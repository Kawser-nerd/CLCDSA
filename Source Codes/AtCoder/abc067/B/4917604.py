import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

n, k = nm()
l = nl()

l.sort(reverse=True)
ans = 0
for i in range(k):
    ans += l[i]
print(ans)