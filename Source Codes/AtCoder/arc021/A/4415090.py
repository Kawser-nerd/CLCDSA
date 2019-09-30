a = [input().split() for _ in range(4)]
for i in range(3):
  for j in range(4):
    if a[i][j] == a[i+1][j] or a[j][i] == a[j][i+1]:
      print("CONTINUE")
      exit()
print("GAMEOVER")