n = int(input())
a = list(map(int,input().split()))
sa = max(a)-min(a)
if sa>1:
  print("No")
  exit()
elif sa == 0:
  if max(a) == n-1:
    print("Yes")
  elif max(a) <= n//2:
    print("Yes")
  else:
    print("No")
else:
  alone = a.count(min(a))
  pair = a.count(max(a))
  ceil = alone + pair//2
  floor = alone + 1
  if floor <= max(a) and max(a)<=ceil:
    print("Yes")
  else:
    print("No")