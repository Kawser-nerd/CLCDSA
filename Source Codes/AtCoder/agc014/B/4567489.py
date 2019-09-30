N,M = map(int,input().split())
L = []
for i in range(M):
  L.append(list(map(int,input().split())))
K = [0]*(10**5)
for i in range(M):
  for j in range(2):
    K[L[i][j]-1] += 1
flag = True
for i in range(10**5):
  if K[i]%2 != 0:
    flag = False
    break
if flag:
  print('YES')
else:
  print('NO')