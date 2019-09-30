import heapq

H, W, T = map(int,input().split())
S = [input() for _ in range(H)]

for i, s in enumerate(S):
  for j, ss in enumerate(s):
    if(ss == 'S'):
      start = i, j
    elif(ss == 'G'):
      goal = i, j

def f(n):
  v = [[False for _ in range(W)]for _ in range(H)]
  q = [(0, start)]
  while q:
    c, (i, j) = heapq.heappop(q)
    for di, dj in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
      ni, nj = i+di, j+dj
      if(not 0 <= ni < H or not 0 <= nj < W):
        continue
      if(v[ni][nj]):
        continue
      v[ni][nj] = True
      nc = c + (n if S[ni][nj] == '#' else 1)
      if((ni, nj) == goal):
        return nc <= T
      heapq.heappush(q, (nc, (ni, nj)))
  return False
low = 1
high = T
while low+1 < high:
  mid = (low+high) // 2
  if(f(mid)):
    low = mid
  else:
    high = mid
print(low)