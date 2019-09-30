x, y, z =map(int,input().split())

if z-y <= 0:
  print('delicious')
elif z-y <= x:
  print('safe')
else:
  print('dangerous')