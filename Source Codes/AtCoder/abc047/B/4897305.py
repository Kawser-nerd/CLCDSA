W, H, N = map(int, input().split())
lx, dy, rx, uy = 0, 0, W, H #??????????
for i in range(N):
    x, y, a = map(int, input().split())
    if a == 1:
        if lx <= x:
            lx = x
    elif a == 2:
        if x <= rx:
            rx = x
    elif a == 3:
        if dy <= y:
            dy = y
    elif a == 4:
        if y <= uy:
            uy = y
if rx - lx <= 0 or uy - dy <= 0:
    print(0)
else:
    print((rx - lx) * (uy - dy))