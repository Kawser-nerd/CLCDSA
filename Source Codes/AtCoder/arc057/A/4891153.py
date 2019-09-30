A, K = map(int,input().split())

day = 0
if K==0:
  day = 2*(10**12)-A
  print(day)
else:
  while A < 2*(10**12):
    A += 1 + K*A
    day += 1
  else:
    print(day)