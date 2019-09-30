x1,y1,x2,y2=map(int, input().split())
x3,y3=x2-(y2-y1),y2+(x2-x1)
x4,y4=x3-(x2-x1),y3-(y2-y1)
print(x3, y3, x4, y4)