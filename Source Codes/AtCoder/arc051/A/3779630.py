x1,y1,r = map(int,input().split())
x2,y2,x3,y3 = map(int,input().split())
 
if x2 <= x1-r and x1+r <= x3 and y2 <= y1-r and y1+r <= y3 :
    print("NO")
else :
    print("YES")
 
dx2 = abs(x1-x2)
dx3 = abs(x1-x3)
dy2 = abs(y1-y2)
dy3 = abs(y1-y3)
d = max(dx2**2+dy2**2,dx2**2+dy3**2,dx3**2+dy2**2,dx3**2+dy3**2)
if d <= r**2 :
    print("NO")
else :
    print("YES")