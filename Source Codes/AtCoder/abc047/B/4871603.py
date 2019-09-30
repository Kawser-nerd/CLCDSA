W, H, N = map(int, input().split())

x0, y0, x1, y1 = 0, 0, W, H
for i in range(N):
    x, y, a = map(int, input().split())
    if a == 1:
        if x0 < x:
            x0 = x
    elif a == 2:
        if x < x1:
            x1 = x
    elif a == 3:
        if y0 < y:
            y0 = y
    else:
        if y < y1:
            y1 = y

if x1-x0<0 or y1-y0<0:
    print(0)
else:
    print((x1-x0)*(y1-y0))