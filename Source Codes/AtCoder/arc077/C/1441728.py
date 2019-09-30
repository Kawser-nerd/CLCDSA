n,m = map(int,input().split())


A = [int(s) for s in input().split()]

A = [(a-A[0])%m for a in A]

end = A[-1]

dist = [0]*m
cycles = 0
x = 0

for a,b in zip(A[:-1],A[1:]):
  cycles += b < a
  dist[b] += (b-a)%m
  x += min((b-a)%m, 1 + b)

dist[0] += 1

res = x

for k in range(m):

  x += dist[k]
  x -= cycles + (k <= end)

  res = min(res, x)

print(res)