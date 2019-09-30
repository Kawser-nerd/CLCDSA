def ans():
  D = list(map(int,input().split()))
  J = list(map(int,input().split()))
  cnt = 0
  for i in range(7):
    cnt += max(D[i], J[i])
  print(cnt)
ans()