H,W = map(int,input().split())
N = int(input())
L = list(map(int,input().split()))
M = [[] for i in range(H)]
c = 0
x = 0
y = 0
for i in range(N):
  while c < L[i]:
    if x != W:
      M[y].append(i+1)
      c += 1
      x += 1
    else:
      y += 1
      x = 1
      M[y].append(i+1)
      c += 1
  c = 0
for i in range(H):
  if i%2 != 0:
    M[i].reverse()
for j in range(H):
  print(' '.join(map(str,M[j])))