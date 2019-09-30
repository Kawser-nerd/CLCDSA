a, b, x=map(int, input().split())
if a==x:
  print("YES")
elif a<=x and  (x-a)<=b:
  print("YES")
else:
  print("NO")