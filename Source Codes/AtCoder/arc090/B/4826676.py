n, m = map(int, input().split())
ed = [[] for _ in range(n)]  # ???
v = [None] * n
for _ in range(m):
  l, r, d = map(int, input().split())
  ed[l-1].append((r-1, d))  # l -> r
  ed[r-1].append((l-1, -d))  # r -> l

visited = [False] * n  # ????????????????

def dfs(start):
  s = [start]
  v[start] = 0
  while s:
    label = s.pop()
    if visited[label] == False:
      visited[label] = True
      for to, dist in ed[label]:
        if v[to] is None:
          v[to] = v[label] + dist
          s.append(to)
        else:
          if v[to] != v[label] + dist:
            return False
  return True

is_exist = True
for i in range(n):
  if v[i] is None:
    if not dfs(i):
      print('No')
      is_exist = False
      break
if is_exist:
  print("Yes")