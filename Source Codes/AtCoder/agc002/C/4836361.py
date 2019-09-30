n, l = map(int, input().split())
alist = list(map(int, input().split()))

preva = alist[0]
is_possible = False
for i, a in enumerate(alist[1:]):
  if preva + a >= l:
    is_possible = True
    break
  preva = a

if not is_possible:
  print('Impossible')
else:
  print('Possible')
  for j in range(1, i+1):
    print(j)
  for j in range(n-1, i+1, -1):
    print(j)
  print(i + 1)