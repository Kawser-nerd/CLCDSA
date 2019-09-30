A, B, Q = map(int, input().split())
s = []
t = []
x = []
for _ in range(A):
    s.append(int(input()))
for _ in range(B):
    t.append(int(input()))
for _ in range(Q):
    x.append(int(input()))

import sys
INT_MAX = sys.maxsize
s.insert(0, -1 * INT_MAX)
s.append(INT_MAX)
t.insert(0, -1 * INT_MAX)
t.append(INT_MAX)

import bisect
for xi in x:
    #print(xi)
    si = bisect.bisect_right(s, xi)
    #si = 0
    #for si, v in enumerate(s):
    #    if v > xi:
    #        break
    ti = bisect.bisect_right(t, xi)
    #ti = 0
    #for ti, v in enumerate(t):
    #    if v > xi:
    #        break
    #print(si, ti)
    sa = s[si]
    ta = t[ti]
    sb = s[si-1]
    tb = t[ti-1]
    #print(sa, sb,ta,tb)
    ans = min([
        abs(xi-sa)+abs(sa-ta),
        abs(xi-sa)+abs(sa-tb),
        abs(xi-sb)+abs(sb-ta),
        abs(xi-sb)+abs(sb-tb),
        abs(xi-ta)+abs(ta-sa),
        abs(xi-ta)+abs(ta-sb),
        abs(xi-tb)+abs(tb-sa),
        abs(xi-tb)+abs(tb-sb)
    ])
    print(ans)