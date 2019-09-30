c = [list(map(int, input().split())) for i in range(3)]
check = 0
a,b = [0]*3,[0]*3

for i in range(2):
  for j in range(2):
    if c[i][j]+c[i+1][j+1] == c[i+1][j]+c[i][j+1]:
      check += 1
if c[0][0]+c[2][2] == c[0][2]+c[2][0]:
  check += 1
      
if check == 5:
  print("Yes")
else:
  print("No")