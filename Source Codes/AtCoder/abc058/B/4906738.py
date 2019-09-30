import sys

ni = lambda: int(sys.stdin.readline().rstrip())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
ns = lambda: sys.stdin.readline().rstrip()

o = list(ns())
e = list(ns())
ans = ''
for i in range(len(e)):
    ans += o[i] + e[i]
if len(o) > len(e):
    ans += o[-1]
print(ans)