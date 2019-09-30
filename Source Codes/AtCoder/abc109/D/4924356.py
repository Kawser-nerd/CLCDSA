H,W = map(int,input().split())
L = []
for i in range(H):
  L.append(list(map(int,input().split())))
i = 0
j = 0
cnt = 0
anslist = []
num = 0
while num < H*W-1:
  if L[i][j]%2 == 0:
    if i%2 == 0 and j == W-1:
      i += 1
    elif i%2 == 0:
      j += 1
    elif i%2 != 0 and j == 0:
      i += 1
    else:
      j -= 1
  else:
    befi,befj = i+1,j+1
    L[i][j] -= 1
    if i%2 == 0 and j == W-1:
      i += 1
    elif i%2 == 0:
      j += 1
    elif i%2 != 0 and j == 0:
      i += 1
    else:
      j -= 1
    L[i][j] += 1
    afti,aftj = i+1,j+1
    anslist.append([befi,befj,afti,aftj])
    cnt += 1
  num += 1
print(cnt)
for i in range(len(anslist)):
  print(anslist[i][0],anslist[i][1],anslist[i][2],anslist[i][3])