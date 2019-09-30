w = int(input())
n,k = map(int,input().split())
lis = [[10 ** 8] * (10 ** 5) for _ in range(100)]
lis[0][0] = 0
ans = 0
for i in range(n):
  a,b = map(int,input().split())
  for j in range(i,-1,-1):
    for h in range(ans + 1):
      lis[j+1][h+b] = min(lis[j][h]+a,lis[j+1][h+b])
  ans += b
cou = 0
for i in range(k+1):
  for j in range(10 ** 5):
    if lis[i][j] <= w:cou = max(cou,j)
print(cou)