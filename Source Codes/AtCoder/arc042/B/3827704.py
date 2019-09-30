x,y = map(int,input().split())
N = int(input())
xy = [list(map(int,input().split())) for _ in range(N)]
xy.append(xy[0])

def between(x,a,b):
    return a <= x <= b

def dist(a,b,c,d):
    res = ((a-c)**2 + (b-d)**2)**.5
    return res

def suichoku(p1,p2,x,y):
    a = (p1[0] - p2[0])
    b = (p1[1] - p2[1])
    mn_x = min(p1[0], p2[0])
    mx_x = max(p1[0], p2[0])
    mn_y = min(p1[1], p2[1])
    mx_y = max(p1[1], p2[1])
    mid_x = (mn_x + mx_x) / 2
    mid_y = (mn_y + mx_y) / 2
    if a == 0:#x????
        if not between(y,mn_y,mx_y):
            return 10**10
        return abs(x - mn_x)
    c = b / a
    if b == 0:#y????
        if not between(x,mn_x,mx_x):
            return 10**10
        return abs(y - mn_y)
    k = - a / b
    xx = -(y - p1[1] - k * x + c * p1[0]) / (k - c)
    yy = (c * y - c * k * x - k * p1[1] + c * k * p1[0]) / (c - k)
    #print(dist(xx, yy, x, y))
    if not( between(xx, mn_x, mx_x) or between(yy, mn_y, mx_y) ):
        return 10**10
    return dist(xx, yy, x, y)

res = 10**10
for (p1,p2) in zip(xy,xy[1:]):
    #print(p1,p2)
    res = min(res, suichoku(p1,p2,x,y))

#????
for l in xy:
    res = min(res, dist(x,y,l[0],l[1]))

print(res)