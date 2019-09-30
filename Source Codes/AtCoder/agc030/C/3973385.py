import math
k = int(input())
if k==1:
  print(1)
  print(1)
  exit()
n = math.ceil(k/4)*2
ans = []
for i in range(n):
  tmp = []
  for j in range(n):
    if i%2 == 0:
      tmp.append((i+j)%n+1)
    else:
      tmp.append(n+(i+j)%n+1)
  ans.append(tmp)
kazu = n*2
while kazu != k:
  for i in range(n):
    for j in range(n):
      if ans[i][j] == kazu:
        ans[i][j]-=n
  kazu-=1
print(n)
for i in range(n):
  print(*ans[i])