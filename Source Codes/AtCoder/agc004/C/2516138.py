H,W=map(int,input().split())
P=[input() for _ in range(H)]

red=[['.' for x in range(W)]for y in range(H)]
blue=[['.' for x in range(W)]for y in range(H)]

for i in range(H):
  red[i][0]='#'
  blue[i][W-1]='#'
  for j in range(1,W-1):
    if i%2==0:
      red[i][j]='#'
    else:
      blue[i][j]='#'

for i in range(1,H-1):
  for j in range(1,W-1):
    if P[i][j]=='#':
      red[i][j]='#'
      blue[i][j]='#'
      
for i in range(H):
  print(''.join(red[i]))
print("")
for i in range(H):
  print(''.join(blue[i]))