x1,y1,x2,y2=map(int,input().split())
x3=x2-(y2-y1)
y3=y2-(x1-x2)
x4=x3-(y3-y2)
y4=y3-(x2-x3)
print('{} {} {} {}'.format(x3,y3,x4,y4))