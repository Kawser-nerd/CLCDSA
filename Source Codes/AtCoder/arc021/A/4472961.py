def ans():
  A = [list(map(int,input().split())) for _ in range(4)]
  f = False
  for i in range(4):
    for j in range(4):
      if(i != 3 and A[i][j] == A[i+1][j]):
        f = True
      elif(i != 0 and A[i][j] == A[i-1][j]):
        f = True
      elif(j != 3 and A[i][j] == A[i][j+1]):
        f = True
      elif(j != 0 and A[i][j] == A[i][j-1]):
        f = True
  if(f):
    print("CONTINUE")
  else:
    print("GAMEOVER")
ans()