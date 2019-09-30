N,M = map(int,input().split())

E = [[False]*N for _ in range(N)]

for n in range(N):
  E[n][n] = True

for _ in range(M):
  a,b = map(int,input().split())
  a,b = a-1,b-1
  E[a][b] = True
  E[b][a] = True


unvisited = set(range(N))
color = [None]*N
components = []

while unvisited:
  v0 = next(iter(unvisited))
  count = [0,0]

  stack = [(v0,False)]
  while stack:
    v,c = stack.pop()
    if color[v] is None:
      color[v] = c
      unvisited.discard(v)
      count[c] += 1
      for u,f in enumerate(E[v]):
        if not f:
          stack.append((u, not c))

    elif color[v] != c:
      print(-1)
      exit()

  components.append(count)

# DP
L = N//2+1
dp = [False]*L


dp[0] = True

for a,b in components:
  ndp = [False]*L
  for i,f in enumerate(dp):
    if f:
      if i+a < L:
        ndp[i+a] = True
      if i+b < L:
        ndp[i+b] = True
  dp = ndp

for i,f in zip(reversed(range(L)), reversed(dp)):
  if f:
    break
j = N - i

print(i*(i-1)//2 + j*(j-1)//2)