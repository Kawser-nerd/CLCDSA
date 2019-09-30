def HasEdge(A, B):
  return all(a < b for a, b in zip(A, B))

def FindPath(adj, start, visited, match):
  if start == -1:
    return True
  for next in adj[start]:
    if visited[next]:
      continue
    visited[next] = True
    if FindPath(adj, match[next], visited, match):
      match[next] = start
      return True
  return False
  
def MaxMatching(adj, n):
  match = [-1] * n
  res = 0
  for i in range(n):
    visited = [False] * n
    if FindPath(adj, i, visited, match):
      res += 1
  #print(match)
  return res

for tc in range(1, int(input()) + 1):
  n, k = map(int, input().split())
  stocks = []
  for i in range(n):
    stocks.append(list(map(int, input().split())))
  #print(stocks)
  adj = []
  for i in range(n):
    toAdd = []
    for j in range(n):
      if (HasEdge(stocks[i], stocks[j])):
        toAdd.append(j)
    adj.append(toAdd)
  #print(adj)
  print ("Case #%d: %d" % (tc, n - MaxMatching(adj, n)))