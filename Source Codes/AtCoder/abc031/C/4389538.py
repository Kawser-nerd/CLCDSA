import sys
inp = sys.stdin.readline

N = int(inp())
A = list(map(int,inp().split()))

ans = -(10**5)
for i in range(N):
  c = -(10**5)
  tmp = 0
  for j in range(N):
    if(i != j):
      l, r = sorted([i, j])
      x = sum(A[l+1:r+1:2])
      if(x > c):
        tmp = j
        c = x
  l, r = sorted([i, tmp])
  ans = max(ans, sum(A[l:r+1:2]))
print(ans)