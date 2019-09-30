x1,y1,r,x2,y2,x3,y3=map(int,open(0).read().split())
f1=f2=0
for x in range(x2,x3+1):
    for y in range(y2,y3+1):
        if ((x-x1)**2+(y-y1)**2)**0.5>r:
            f1=1
            break
    if f1:
        break
if x2>x1-1 or x1+r>x3 or y2>y1-r or y1+r>y3:
    f2=1
if f2:
    print('YES')
else:
    print('NO')
if f1:
    print('YES')
else:
    print('NO')