x1, y1, r = map(int, input().split())
x2,y2,x3,y3 = map(int, input().split())
if x3-x1>=r and x1-x2>=r and y3-y1>=r and y1-y2>=r:
  print("NO")
  print("YES")
elif (x3-x1)**2+(y3-y1)**2<=r*r and (x3-x1)**2+(y2-y1)**2<=r*r and (x2-x1)**2+(y3-y1)**2<=r*r and (x2-x1)**2+(y2-y1)**2<=r*r:
  print("YES")
  print("NO")
else:
  print("YES")
  print("YES")