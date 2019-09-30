from itertools import chain

N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

IMP = 100

dp = [[IMP for _ in range(51)] for _ in range(51)]

for i in range(51):
  dp[i][i] = 0
  for j in range(i):
    for m in range(1,51):
      if dp[i%m][j] != IMP:
        dp[i][j] = m
        break


if max(dp[x][y] for x,y in zip(A,B)) == IMP:
  print(-1)
else:
  cost = 0
  m = max(dp[x][y] for x,y in zip(A,B))
  AL = [{a} for a in A]

  def candmin(al,b):
    m = min(dp[a][b] for a in al)
    al.discard(a for a in al if dp[a][b] > m)
    return m

  while m != 0:
    for i,(al,b) in enumerate(zip(AL,B)):
      AL[i] |= set(a%m for a in al)
    cost += 2**m

    m = max(candmin(al,b) for al,b in zip(AL,B))

  print(cost)