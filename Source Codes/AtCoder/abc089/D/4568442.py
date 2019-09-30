H,W,D = map(int,input().split())
L = []
for i in range(H):
  L.append(list(map(int,input().split())))
Q = int(input())
query = []
for i in range(Q):
  query.append(list(map(int,input().split())))
P = [[0,0]]*(H*W)
for i in range(H):
  for j in range(W):
    P[L[i][j]-1] = [i,j]
dp = [0]*(H*W)
for i in range(D):
  dp[i] = 0
  cnt = i+D
  while cnt < H*W:
    dp[cnt] = dp[cnt-D]+abs(P[cnt][0]-P[cnt-D][0])+abs(P[cnt][1]-P[cnt-D][1])
    cnt = cnt+D
for j in range(Q):
  print(dp[query[j][1]-1]-dp[query[j][0]-1])