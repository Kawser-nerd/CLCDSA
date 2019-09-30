n, x = map(int, input().split())
alist = list(sorted(map(int, input().split())))

if sum(alist) == x:
  print(n)
else:
  suma = 0
  k = 0
  for a in alist:
    if suma <= x:
      suma += a
      k += 1
  print(k - 1)