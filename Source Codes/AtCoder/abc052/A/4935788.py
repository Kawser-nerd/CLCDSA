a = list(map(int, input().split()))
if a[0] * a[1] == a[2] * a[3]:
  print(a[0]*a[1])
elif a[0] * a[1] > a[2] * a[3]:
  print(a[0]*a[1])
else:
  print(a[2]*a[3])