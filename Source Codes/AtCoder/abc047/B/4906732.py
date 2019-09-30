w,h,n=[int(i) for i in input().split(' ')]
x1,x2,y1,y2=0,w,0,h
for i in range(n):
  x,y,a=[int(i) for i in input().split(' ')]
  if a==1:
    x1=max(x1,x)
  if a==2:
    x2=min(x2,x)
  if a==3:
    y1=max(y1,y)
  if a==4:
    y2=min(y2,y)
    
if y2<=y1 or x2 <= x1:
  print(0)
else:
  print(max(0,(y2-y1)*(x2-x1)))