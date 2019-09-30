a = list(map(int,input().split()))
if a[0] != a[1] and a[0] != a[2] and a[1] != a[2]:
  print(3)
elif a[0] == a[1] and a[0] != a[2]:
  print(2)
elif a[0] != a[1] and a[0] == a[2]:
  print(2)
elif a[0] != a[1] and a[1] == a[2]:
  print(2)
elif a[0] == a[1] == a[2]:
  print(1)