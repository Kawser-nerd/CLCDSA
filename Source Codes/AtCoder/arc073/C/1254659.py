N = int(input())
xmin = ymin = float('inf')
xmax = ymax = 0
p = []
for i in range(N):
    x,y = map(int, input().split())
    if x > y : 
        x,y= y,x
    p.append((x, y))
    if x < xmin:
        xmin = x
    elif x > xmax:
        xmax = x
    if y < ymin:
        ymin = y
    elif y > ymax:
        ymax = y
ret = (ymax-ymin) * (xmax-xmin)


p.sort()
dx = p[-1][0] - p[0][0]
ymin = p[0][0]
tymin = float('inf')
for i in range(N-1):
    # print(i, dx, (xmax, xmin), end=' ==> ')
    tymin = min(tymin, p[i][1])
    xmax = max(xmax, p[i][1])
    xmin = min(tymin, p[i+1][0])
    dx = min(dx, xmax - xmin)
    if tymin < p[i+1][0]:
        break
    # print(i, dx, (xmax, xmin))

print(min(ret, (ymax-ymin) * dx))