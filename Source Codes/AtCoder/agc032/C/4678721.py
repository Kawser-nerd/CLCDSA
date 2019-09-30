n, m = map(int, input().split())

graph = {}
for u in range(1, n + 1):
  graph[u] = set()
for i in range(m):
  u, v = map(int, input().split())
  graph[u].add(v)
  graph[v].add(u)
  
# check if has eulerian cycle
odd = 0
v6 = []
v4 = []
for u in range(1, n + 1): 
  if len(graph[u]) % 2 != 0: 
    odd += 1
    break
  elif len(graph[u]) >= 6:
    v6.append(u)
  elif len(graph[u]) == 4:
    v4.append(u)
if odd: 
  print('No')
else:
  # for has 3 cycles if any vertices has minimal six degree
  # or more than 2 vertices have 4 degrees
  if len(v6) > 0 or len(v4) > 2:
    print('Yes')
  # if vertices with 4 degrees less than 2
  elif len(v4) < 2:
    print('No')
  else:
    s = v4.pop()
    t = v4.pop()
    has_3_cycles= False
    for c in graph[s]:
      visited = {s, t}
      q = [c]
      while q:
        v = q.pop()
        if v in visited:
          continue
        visited.add(v)
        for u in graph[v]:
          if v != c and u == s:
            has_3_cycles = True
            break
          if u not in visited:
            q.append(u)
        if has_3_cycles:
          break
      if has_3_cycles:
        break
    print('Yes') if has_3_cycles else print('No')