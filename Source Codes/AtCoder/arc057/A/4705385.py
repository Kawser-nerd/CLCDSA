a,k = map(int,input().split())

if k ==0:
  print(2*10**12 - a)

else:
  count = 0
  while a < 2*10**12:
    count += 1
    a += 1 + a*k
  print(count)