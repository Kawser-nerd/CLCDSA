D, N = map(int,input().split())
if N == 100:
  N=101
if D == 0:
  print(N)
elif D == 1:
  print(N*100)
else:
  print(N*10000)