L = []
for i in range(4):
  L.append(list(map(int,input().split())))
flag = False
for i in range(4):
  for j in range(3):
    if L[i][j] == L[i][j+1]:
      flag = True
      break
    else:
      for k in range(3):
        for l in range(4):
          if L[k][l] == L[k+1][l]:
            flag = True
            break
if flag:
  print('CONTINUE')
else:
  print('GAMEOVER')