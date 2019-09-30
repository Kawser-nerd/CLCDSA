def ans():
  m, n, N = map(int,input().split())
  cnt = N
  while N >= m:
    x = N//m*n
    cnt += x
    N = x + N%m
  print(cnt)
ans()