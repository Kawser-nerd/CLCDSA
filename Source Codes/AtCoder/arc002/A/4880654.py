y=int(input())
if y%400==0:
  print('YES')
  exit()
elif y%100==0:
  print('NO')
  exit()
elif y%4==0:
  print('YES')
  exit()
else:
  print('NO')