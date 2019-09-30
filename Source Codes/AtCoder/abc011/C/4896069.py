n = int(input())
ng = [int(input())for _ in range(3)]
if n in ng:
  print('NO')
  exit()
cnt=0
while n != 0:
  if n - 3 not in ng and n - 3 >= 0:
    n -= 3
  elif n - 2 not in ng and n - 2 >= 0:
    n -= 2
  elif n - 1 not in ng and n - 1 >= 0:
    n -= 1
  else:
    print('NO')
    exit()
  cnt += 1
if cnt > 100:
  print('NO')
else:
  print('YES')