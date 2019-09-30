A, D = map(int, input().split())

if (A+1)*D >= A*(D+1):
  print((A+1)*D)
elif (A+1)*D < A*(D+1):
  print(A*(D+1))