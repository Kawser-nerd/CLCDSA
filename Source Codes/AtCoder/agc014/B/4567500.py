N,M = map(int,input().split())
K = [0]*(10**5)
for i in range(M):
  P,Q = map(int,input().split())
  K[P-1] += 1
  K[Q-1] += 1
flag = True
for i in range(10**5):
  if K[i]%2 != 0:
    flag = False
    break
if flag:
  print('YES')
else:
  print('NO')