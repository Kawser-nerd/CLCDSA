import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

h, w = nm()
a = [['#'] + list(map(str, sys.stdin.readline().split())) + ['#'] for _ in range(h)]
a.insert(0, ['#' for _ in range(w + 2)])
a.append(['#' for _ in range(w + 2)])
for i in range(h + 2):
    print(''.join(a[i]))