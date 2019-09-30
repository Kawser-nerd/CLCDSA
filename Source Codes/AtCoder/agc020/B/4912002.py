k = int(input())
alist = list(map(int, input().split()))

if alist[-1] != 2:
  print(-1)
else:
  mina = 2
  maxa = 3
  is_nn = False
  for a in alist[::-1][1:]:
    mina = a * ((mina + a - 1) // a)
    maxa = a * (maxa // a) + a - 1
    if mina >= maxa or mina // a == maxa == a:
      is_nn = True
      break

  if is_nn:
    print(-1)
  else:
    print(mina, maxa)