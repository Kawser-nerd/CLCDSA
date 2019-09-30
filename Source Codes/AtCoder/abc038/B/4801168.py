x, y= map(int,input().split())
a, b = map(int,input().split())
if x > y :
  x, y = y , x
if a > b :
  a, b = b , a
if x == a or x == b or y == a or y == b:
  print("YES")
else:
  print("NO")