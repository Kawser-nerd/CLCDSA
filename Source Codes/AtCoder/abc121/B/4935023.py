n,m,c = list(map(int, input().split()))
b = list(map(int, input().split()))
l = [list(map(int, input().split())) for i in range(n)]

cnt=0
tot=0

for i in range(n):
  for j in range(m):
    tot += l[i][j] * b[j]
  tot = tot + c
  if (tot > 0):
    cnt+=1
  tot=0

print(cnt)