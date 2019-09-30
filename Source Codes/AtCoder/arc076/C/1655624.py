#!/usr/bin/env python3
w, h, n = map(int, input().split())
def proj(x, y):
    if y == 0:
        return x
    elif x == w:
        return w + y
    elif y == h:
        return w + h + (w - x)
    elif x == 0:
        return w + h + w + (h - y)
    else:
        return None
ps = []
for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    p1 = proj(x1, y1)
    p2 = proj(x2, y2)
    if p1 is not None and p2 is not None:
        ps += [ (p1, i), (p2, i) ]
ps.sort()
stk = []
for _, i in ps:
    if stk and stk[-1] == i:
        stk.pop()
    else:
        stk.append(i)
result = not stk
print([ 'NO', 'YES' ][ result ])