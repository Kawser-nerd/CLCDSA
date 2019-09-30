l,x,y,s,d=map(int, input().split())
if d>=s:
    if y!=x:a=(s+l-d)/(y-x)
    b=(d-s)/(x+y)
else:
    if y!=x:a=(s-d)/(y-x)
    b=(d-s+l)/(y+x)
if y<=x:print(b)
else:print(min(a,b))