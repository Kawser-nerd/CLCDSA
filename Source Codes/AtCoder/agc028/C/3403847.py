n = int(input())
b = []
ASUM = 0
BSUM = 0
for i in range(n):
  x,y = map(int,input().split())
  b.append([x,i])
  b.append([y,i])
  ASUM += x
  BSUM += y
a = sorted(b)
tuka = [0] * n
flag = 0
for i in range(n):
  if tuka[a[i][1]] == 1:
    flag = 1
    break
  else:
    tuka[a[i][1]] = 1
ans = 0
for i in range(n):
  ans += a[i][0]
if flag == 0:
  tmp = float("inf")
  las = a[n-1]
  bu = a[n-2]
  for i in range(n):
    if las[1] == i:
      tmp = min(tmp,max(b[i*2][0],b[i*2+1][0])-bu[0])
    else:
      tmp = min(tmp,max(b[i*2][0],b[i*2+1][0])-las[0])
  ans += tmp
ans = min(ans,ASUM,BSUM)
print(ans)