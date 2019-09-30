import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

sx, sy, tx, ty = nm()

ans = ''

ans += 'L'
ans += 'U' * (ty - sy + 1)
ans += 'R' * (tx - sx + 1)
ans += 'D'

ans += 'L' * (tx - sx)
ans += 'D' * (ty - sy)

ans += 'D'
ans += 'R' * (tx - sx + 1)
ans += 'U' * (ty - sy + 1)
ans += 'L'

ans += 'D' * (ty - sy)
ans += 'L' * (tx - sx)

print(ans)