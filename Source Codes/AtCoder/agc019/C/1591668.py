from math import pi
from bisect import bisect_left as bl

def LIS(p) :
    route = []
    for y in p :
        pos = bl(route, y)
        if len(route) <= pos : route.append(y)
        else : route[pos] = y
    return len(route)


def main() :
    x1, y1, x2, y2 = map(int, input().split())
    xfilp = 1
    yflip = 1
    if x1 > x2 :
        xfilp = -1
        x1, x2 = x2, x1
    if y1 > y2 :
        yflip = -1
        y1, y2 = y2, y1
    n = int(input())
    p = []
    for i in range(n) :
        x, y = map(int, input().split())
        if x1 <= x <= x2 and y1 <= y <= y2 :
            p.append((x * xfilp, y * yflip))
    p = [y for x, y in sorted(p, key=lambda t:t[0])]
    foun = LIS(p)
    ans = 100*(x2-x1 + y2-y1) - (20 - pi*5)*foun
    if foun == min(x2-x1+1, y2-y1+1) :
        ans += pi*5
    print(ans)

main()