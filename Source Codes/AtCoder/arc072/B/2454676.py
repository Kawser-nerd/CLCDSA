X,Y=map(int,input().split())
if max(X,Y)-min(X,Y) > 1:
  print("Alice")
else:
  print("Brown")