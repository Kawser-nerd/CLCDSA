import math
x,y = map(int,input().split())
N = int(input())
ps = [tuple(map(int,input().split())) for i in range(N)]
ps.append(ps[0])

def dist(x1,y1,x2,y2):
    return math.sqrt((x1-x2)**2 + (y1-y2)**2)

def area(x1,y1,x2,y2,x3,y3):
    a = dist(x1,y1,x2,y2)
    b = dist(x2,y2,x3,y3)
    c = dist(x3,y3,x1,y1)
    s = (a+b+c) / 2
    return math.sqrt(s*(s-a)*(s-b)*(s-c))

ans = float('inf')
for (x1,y1),(x2,y2) in zip(ps,ps[1:]):
    a = area(x1,y1,x2,y2,x,y)
    bottom = dist(x1,y1,x2,y2)
    h = a / bottom * 2
    ans = min(ans, h)

print(ans)