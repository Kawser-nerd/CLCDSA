x1,y1,r=map(int,input().split())
x2,y2,x3,y3=map(int,input().split())
if (x2<=x1-r) and (x1+r<=x3) and (y2<=y1-r) and (y1+r<=y3):
    print("NO")
else:
    print("YES")
tmp=0
L=[(x2,y2),(x2,y3),(x3,y2),(x3,y3)]
for p in L:
    x,y=p
    if (x-x1)**2+(y-y1)**2<=r*r:
        tmp+=1
if tmp==4:
    print("NO")
else:
    print("YES")