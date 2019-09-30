from sys import stdin
import copy

def feasible(graph, removed, start):
  visited = set()

  def dfs(u):
    if u in visited or u in removed:
      return
    visited.add(u)
    for v in graph[u]:
      dfs(v)

  dfs(start)
  return len(visited) == len(graph) - len(removed)

def solve(start, graph, postcodes):
  stack = [start]
  visited = set(stack)
  ans = postcodes[start]
  removed = set()
  while len(visited) < len(postcodes):
    best = 100000000
    bestStack = None
    bestNeighbor = None
    for i in range(len(stack), 0, -1):
      if not feasible(graph, removed | set(stack[i:]), start):
        continue
      for v in graph[stack[i-1]]:
        if v not in visited and postcodes[v] < best:
          best = postcodes[v]
          bestStack = i
          bestNeighbor = v
    removed |= set(stack[bestStack:])
    stack = stack[:bestStack]
    stack.append(bestNeighbor)
    visited.add(bestNeighbor)
    ans = ans * 100000 + postcodes[bestNeighbor]
  return ans

T = int(stdin.readline())

for no in range(1, T+1):
  N, M = map(int, stdin.readline().split())
  postcodes = {}
  graph = {i: set() for i in range(1,N+1)}
  for i in range(1, N+1):
    postcodes[i] = int(stdin.readline())
  for i in range(M):
    x, y = map(int, stdin.readline().split())
    graph[x].add(y)
    graph[y].add(x)
  bestStart = None
  bestPostcode = 10000000000
  for u in postcodes:
    if postcodes[u] < bestPostcode:
      bestPostcode = postcodes[u]
      bestStart = u
  print("Case #{}: {}".format(no, solve(bestStart, graph, postcodes)))
