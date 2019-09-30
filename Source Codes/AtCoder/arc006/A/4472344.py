def ans():
  E = list(map(int,input().split()))
  B = int(input())
  L = list(map(int,input().split()))
  cnt = 0
  f = False
  for i in range(6):
    if(L[i] in E):
      cnt += 1
    elif(L[i] == B):
      f = True
  res = 0
  if(cnt == 6):
    res = 1
  elif(cnt == 5):
    if(f):
      res = 2
    else:
      res = 3
  elif(cnt == 4):
    res = 4
  elif(cnt == 3):
    res = 5
  print(res)
ans()