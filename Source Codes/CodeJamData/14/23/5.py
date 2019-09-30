def getints():
  return [int(x.strip()) for x in raw_input().split(' ')]

cases = input()
for case in range(cases):
  N,M = getints()
  vert = [input() for i in range(N)]
  adj = [set() for i in range(N)]
  for i in range(M):
    a,b=getints()
    a-=1
    b-=1
    adj[a].add(b)
    adj[b].add(a)

  undo = []
  def removeall(a):
    for b in adj[a]:
      adj[b].remove(a)
      undo.append((a,b))
    adj[a] = set()

  def undoall():
    for a,b in undo:
      adj[a].add(b)
      adj[b].add(a)
    undo[:] = []

  def isdisconn(v, already):
    visited = [False for i in range(N)]
    def dfs(v):
      visited[v] = True
      for a in adj[v]:
        if not visited[a]:
          dfs(a)
    dfs(v)
    for i in range(N):
      if not visited[i] and not already[i]:
        return True
    return False

  order = zip(vert, range(N))
  order = sorted(order)

  root = order[0][1]
  frontier = [root]
  count = 1
  included = [False for i in range(N)]
  included[root] = True
  result = [order[0][0]]

  while count < N:
    for (z,v) in order:
      if included[v]:
        continue
      if v in adj[frontier[-1]]:
        frontier.append(v)
        included[v] = True
        result.append(z)
        count+=1
        break
      adjacents = [i for i in range(len(frontier)-1,-1,-1) if v in adj[frontier[i]]]
      if len(adjacents) == 0:
        continue
      i = adjacents[0]
      for j in range(i+1,len(frontier)):
        removeall(frontier[j])
      if isdisconn(root, included):
        undoall()
        continue
      undo[:] = []
      frontier = frontier[:i+1]
      frontier.append(v)
      included[v] = True
      result.append(z)
      count+=1
      break
  print 'Case #' + str(case+1) + ':', ''.join([str(x) for x in result])