W, H, N = map(int, input().rstrip().split())
xya = [list(map(int, input().rstrip().split())) for _ in range(N)]
xy = [[0]*H for _ in range(W)]
for i in xya:
    x_y = i[:2]
    a = i[2]
    if a == 1:
        for j in range(x_y[0]):
            xy[j] = list(map(lambda x: x+1, xy[j]))
    elif a == 2:
        for j in range(x_y[0],W):
            xy[j] = list(map(lambda x: x+1, xy[j]))
    elif a == 3:
        y = x_y[1]
        for j in range(W):
            for k in range(H):
                xy[j][k] += 1 if k < y else 0  
    else:
        y = x_y[1]
        for j in range(W):
            for k in range(H):
                xy[j][k] += 1 if k >= y else 0
area = 0
for i in xy:
    area += i.count(0)
print(area)