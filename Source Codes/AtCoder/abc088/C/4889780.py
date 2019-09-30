C = [0]*3
C1 = [[0]*2]*3
C2 = [[0]*3]*2
flg = False
for i in range(3):
  C[i] = list(map(int, input().split()))
for i in range(2):
  for j in range(2):
    if(C[i][j] -C[i][j+1] != C[i+1][j] -C[i+1][j+1]):
      flg = True
for i in range(2):
  for j in range(2):
    if(C[i][j] -C[i+1][j] != C[i][j+1] -C[i+1][j+1]):
      flg = True
print("No" if flg else "Yes")