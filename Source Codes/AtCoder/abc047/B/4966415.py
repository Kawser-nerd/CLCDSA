W, H, N = map(int, input().split())
xya = [''] * N
for i in range(N):
    xya[i] = list(map(int, input().split()))

h, w = H, W
x0, y0 = 0, 0
ans = 1

for i in range(N):
    if xya[i][2] == 1:
        if xya[i][0] <= w:
            x0 = max(xya[i][0], x0)
        else:
            ans = 0
    elif xya[i][2] == 2:
        if x0 <= xya[i][0] and xya[i][0] <= w:
            w = xya[i][0]
        elif xya[i][0] < x0:
            ans = 0
    elif xya[i][2] == 3:
        if xya[i][1] <= h:
            y0 = max(xya[i][1], y0)
        else:
            ans = 0
    else:
        if y0 <= xya[i][1] and xya[i][1] <= h:
            h = xya[i][1]
        elif xya[i][1] < y0:
            ans = 0
if ans != 0:
    ans = (w - x0) * (h - y0)
print(ans)