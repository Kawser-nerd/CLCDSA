x1, y1, r = map(int, input().split())
x2, y2, x3, y3 = map(int, input().split())
if x2+r <= x1 <= x3-r and y2+r <= y1 <= y3-r:
  print("NO")
else:
  print("YES")
if max(abs(x3-x1), abs(x2-x1))**2 + max(abs(y3-y1), abs(y2-y1))**2 <= r**2:
  print("NO")
else:
  print("YES")