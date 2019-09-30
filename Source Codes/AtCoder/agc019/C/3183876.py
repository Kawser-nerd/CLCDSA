import math
from bisect import bisect
x1,y1,x2,y2 = map(int,input().split())
N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]
src.sort()
if x1 > x2:
    x1,x2 = x2,x1
    y1,y2 = y2,y1

arc = 5 * math.pi

if x1 == x2:
    if y1 > y2:
        y1,y2 = y2,y1
    ans = 100 * (y2-y1)
    for x,y in src:
        if x == x1 and y1 < y < y2:
            ans += arc*2 - 20
            break
    print(ans)
    exit()

if y1 == y2:
    if x1 > x2:
        x1,x2 = x2,x1
    ans = 100 * (x2-x1)
    for x,y in src:
        if y == y1 and x1 < x < x2:
            ans += arc*2 - 20
            break
    print(ans)
    exit()

if y1 < y2:
    lis = []
    for x,y in src:
        if x < x1: continue
        if x > x2: break
        if not y1 <= y <= y2: continue
        i = bisect(lis, y)
        if i == len(lis):
            lis.append(y)
        else:
            lis[i] = y
    ans = 100 * (x2-x1 + y2-y1)
    if len(lis) in (x2-x1+1, y2-y1+1):
        ans += (len(lis)-1) * (arc - 20)
        ans += arc*2 - 20
    else:
        ans += len(lis) * (arc - 20)
    print(ans)
else:
    lds = []
    for x,y in src:
        if x < x1: continue
        if x > x2: break
        if not y2 <= y <= y1: continue
        i = bisect(lds, -y)
        if i == len(lds):
            lds.append(-y)
        else:
            lds[i] = -y
    ans = 100 * (x2-x1 + y1-y2)
    if len(lds) in (x2-x1+1, y1-y2+1):
        ans += (len(lds)-1) * (arc - 20)
        ans += arc*2 - 20
    else:
        ans += len(lds) * (arc - 20)
    print(ans)