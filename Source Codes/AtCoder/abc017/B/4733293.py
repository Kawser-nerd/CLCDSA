x = str(input())
if x.replace('ch', '').replace('o', '').replace('k', '').replace('u', '') == '':
  print('YES')
else:
  print('NO')