N,K = map(int,input().split())
L = []
p = 0
c = 0
flag = True
for i in range(N):
  L.append(int(input()))
for j in range(N-2):
  p = L[j]+L[j+1]+L[j+2]
  if p < K:
    flag = False
    c = j+3
    break
  else:
    None
if flag:
  print(-1)
else:
  print(c)