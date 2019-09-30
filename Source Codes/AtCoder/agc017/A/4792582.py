n, p = map(int, input().split())
alist = list(map(int, input().split()))

odda = 0
for a in alist:
  if a % 2 == 1:
    odda += 1

if odda == 0:
  if p == 0:
    print(pow(2, n))
  else:
    print(0)
else:
  print(pow(2, n-1))