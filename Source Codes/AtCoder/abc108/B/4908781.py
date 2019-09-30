x1,y1,x2,y2 = map(int,input().split())
xnum = x2-x1
ynum = y2-y1
x3,y3 = x1-ynum,y1+xnum
x4,y4 = x2-ynum,y2+xnum
print(x4,y4,x3,y3)