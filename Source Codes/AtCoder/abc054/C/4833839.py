N, M = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(M)]
visited = {i:False for i in range(N)}
visited[0] = True
ans = 0

def DFS(x):
#  print(visited)
  global ans
  nextx = []
  if False not in visited.values():
    ans += 1
    return
  for i in range(M):
    if x in ab[i]:
      xcol = ab[i].index(x)
      if visited[ab[i][1-xcol]-1]:
        continue
      else:
        nextx.append(ab[i][1-xcol])
#  print(nextx)
  for i in nextx:
    visited[i-1] = True
    DFS(i)
    visited[i-1] = False
  return

DFS(1)
print(ans)