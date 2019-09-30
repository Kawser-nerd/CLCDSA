def ans():
  N, M = map(int,input().split())
  for i in range(1,N+1):
    if(i != M):
      print(i)
      break
ans()