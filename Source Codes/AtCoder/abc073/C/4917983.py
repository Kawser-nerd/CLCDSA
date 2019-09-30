import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

n = ni()

a = [ni() for _ in range(n)]
c = collections.Counter(a).values()
ans = 0
for t in c:
    if t % 2 != 0:
        ans += 1
print(ans)