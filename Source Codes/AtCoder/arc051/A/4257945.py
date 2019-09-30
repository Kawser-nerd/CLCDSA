x1,y1,r = map(int,input().split())
x2,y2,x3,y3 = map(int,input().split())
if x2 <= x1-r and x1+r <= x3 and y2 <= y1-r and y1+r <= y3:
  print('NO')
  print('YES')
elif (x1-x2)**2+(y1-y2)**2 <= r**2 and (x1-x3)**2+(y1-y3)**2 <= r**2 and (x1-x2)**2+(y1-y3)**2 <= r**2 and (x1-x3)**2+(y1-y2)**2 <= r**2:
  print('YES')
  print('NO')
else:
  print('YES')
  print('YES')