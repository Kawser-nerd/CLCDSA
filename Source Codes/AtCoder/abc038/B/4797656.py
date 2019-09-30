n = [list(map(int,input().split())) for i in range(2)]
if n[0][0] in n[1] or n[0][1] in n[1]:
  print('YES')
else:
  print('NO')