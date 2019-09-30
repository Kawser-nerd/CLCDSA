import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

s = list(ns())
ans = []
for i in range(0, len(s), 2):
    ans.append(s[i])
print(''.join(ans))