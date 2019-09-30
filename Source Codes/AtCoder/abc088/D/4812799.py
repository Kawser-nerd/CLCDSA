from collections import deque

h, w = [int(item) for item in input().split()]
s = [input() for _ in range(h)]
dist = [[-1] * w for _ in range(h)]

black = 0
for line in s:
  black += line.count("#")

que = deque()
que.append([0,0])
dist[0][0] = 1
while que:
  x, y = que.popleft()
  for i, j in [(1,0), (-1,0), (0,1), (0,-1)]:
    nx = x + i
    ny = y + j
    if nx < 0 or nx >= h or ny < 0 or ny >= w:
      continue
    if s[nx][ny] == "#":
      continue
    if dist[nx][ny] == -1:
      dist[nx][ny] = dist[x][y] + 1
      que.append([nx, ny])

if dist[h-1][w-1] == -1:
  print(-1)
else:
  print(h*w - dist[h-1][w-1] - black)