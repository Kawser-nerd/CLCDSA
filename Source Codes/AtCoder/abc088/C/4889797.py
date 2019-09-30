C = [0]*3
flg = True
for i in range(3):
  C[i] = list(map(int, input().split()))
for i in range(2):
  for j in range(2):
    if(C[i][j] -C[i][j+1] != C[i+1][j] -C[i+1][j+1]):
      flg = False
for i in range(2):
  for j in range(2):
    if(C[i][j] -C[i+1][j] != C[i][j+1] -C[i+1][j+1]):
      flg = False
print("Yes" if flg else "No")