import sys
from math import sin, cos, radians

H, W = sorted(map(int, input().split()))
input()
for (box_h, box_w) in (sorted(map(int, l.split())) for l in sys.stdin):
    if H <= box_h and W <= box_w:
        print("YES")
        continue
    ok, ng = 0.0, radians(90)
    while ng-ok > 1e-12:
        mid = (ok+ng) / 2
        if W*sin(mid) + H*cos(mid) <= box_h:
            ok = mid
        else:
            ng = mid
    _w = W*cos(ok) + H*cos(radians(90)-ok)
    _h = W*sin(ok) + H*cos(ok)
    if _w <= box_w and _h <= box_h:
        print("YES")
    else:
        print("NO")