N = int(input())
xyh = []
xx, yy, hh = -1, -1, -1
for _ in range(N):
    x, y, h = map(int, input().split())
    xyh.append([x, y, h])
    if h > 0:
        xx, yy, hh = x, y, h

ansX = -1
ansY = -1
ansH = -1
for cx in range(0, 101):
    for cy in range(0, 101):
        H = hh + abs(xx - cx) + abs(yy - cy)
        for x, y, h in xyh:
            if h == 0 and H > abs(x - cx) + abs(y - cy):
                H = -1
                break
            if h > 0 and H != h + abs(x - cx) + abs(y - cy):
                H = -1
                break
        if H > 0:
            ansH = H
            ansX = cx
            ansY = cy

print(ansX, ansY, ansH)