import sys
inp = sys.stdin.readline

R, C, K = map(int,inp().split())
N = int(inp())

r = [0 for _ in range(N)]
c = [0 for _ in range(N)]
x = [0 for _ in range(R)]
y = [0 for _ in range(C)]
for i in range(N):
  r[i], c[i] = map(int,inp().split())
  r[i] -= 1
  c[i] -= 1
  x[r[i]] += 1
  y[c[i]] += 1

a = [0 for i in range(C+1)]
b = [0 for i in range(R+1)]
for i in range(R):
  a[x[i]] += 1
for i in range(C):
  b[y[i]] += 1

ans1 = 0
ans2 = 0
for i in range(K+1):
  if(0 <= i <= C and 0 <= K-i <= R):
    ans1 += a[i] * b[K-i]
for i in range(N):
  if(x[r[i]]+y[c[i]] == K):
    ans1 -= 1
  if(x[r[i]]+y[c[i]] == K+1):
    ans2 += 1
print(ans1+ans2)