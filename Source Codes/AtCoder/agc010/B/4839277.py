n = int(input())
alist = list(map(int, input().split()))
suma = sum(alist)

if suma % (n * (n+1) // 2) != 0:
  print('NO')
else:
  k = suma // (n * (n+1) // 2)
  da = []
  for preva, a in zip(alist, alist[1:]):
    da.append(a - preva - k)
  da.append(alist[0] - alist[-1] - k)
  nk = 0
  is_a = True
  for _da in da:
    if abs(_da) % n != 0:
      is_a = False
      break
    nk += abs(_da) // n
  if not is_a:
    print('NO')
  else:
    if nk != k:
      print('NO')
    else:
      print('YES')