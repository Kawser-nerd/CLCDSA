N,M = map(int,input().split())
L = []
for i in range(N):
  K = input()
  S = []
  for j in range(M):
    S.append(int(K[j]))
  L.append(S)
dy_dx = [[1,0],[0,1],[-1,0],[0,-1]]
ans = []
for i in range(N):
  ans_sub = [0]*M
  ans.append(ans_sub)
for i in range(N):
  for j in range(1,M-1):
    if L[i][j] != 0:
      T = L[i][j]
      ans[i+1][j] += T
      for k in range(4):
        L[i+1+dy_dx[k][0]][j+dy_dx[k][1]] -= T
for i in range(N):
  s = ''
  for j in range(M):
    s += str(ans[i][j])
  print(s)