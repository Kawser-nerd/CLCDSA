xx,yy,W = input().split()
x,y = int(xx) - 1, int(yy) - 1 
ps = [input() for _ in range(9)]
dic_dx = {'R':1,'L':-1,'U':0, 'D':0,'RU':1, 'RD':1,'LU':-1,'LD':-1}
dic_dy = {'R':0,'L':0, 'U':-1,'D':1,'RU':-1,'RD':1,'LU':-1,'LD':1 }
dx = dic_dx[W]
dy = dic_dy[W]

s = ps[y][x]
for _ in range(3):
    if (x == 0) and (dx == -1):
        x = 1
        dx = 1
    elif (x == 8) and (dx == 1):
        x = 7
        dx = -1
    else:
        x += dx

    if  (y == 0) and (dy == -1):
        y = 1
        dy = 1
    elif (y == 8) and (dy == 1):
        y = 7
        dy = -1
    else:
        y += dy

    s += ps[y][x]
print(s)