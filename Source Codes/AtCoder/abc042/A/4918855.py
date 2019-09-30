x = list(map(int, input().split()))
if x.count(5) == 2 and x.count(7) == 1:
  print('YES')
else:
  print('NO')