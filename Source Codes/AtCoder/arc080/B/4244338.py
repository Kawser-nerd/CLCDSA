H, W = (int(i) for i in input().split())
N = int(input())
A = [int(i) for i in input().split()]
C = []
for i in range(N):
  for j in range(A[i]):
    C.append(i+1)
ans = [[0]*W for i in range(H)]
for i in range(H*W):
  y = i // W
  if y%2==0:
    x = i%W
  else:
    x = W-1-i%W
  ans[y][x] = C[i]
for i in range(H):
  ans[i] = [str(a) for a in ans[i]]
  print(" ".join(ans[i]))