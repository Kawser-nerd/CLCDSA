N = input()
f = False
for i in N:
  if i == '3':
    f = True
if int(N)%3==0:
  f = True
if f:
  print('YES')
else:
  print('NO')