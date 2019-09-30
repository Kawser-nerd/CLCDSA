from collections import defaultdict

MOD = 1000000007

lol = 1000
ncr = [[0 for i in range(lol)] for j in range(lol)]
for i in range(lol):
  ncr[i][0] = 1
  ncr[i][i] = 1
for i in range(2,lol):
  for j in range(1, i):
    ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1]

def prob(n, list):
  answers = range(n)
  for l in range(n):
    answers[l] = ncr[n][l]
    for i in list:
      answers[l] *= ncr[n-l][i]
      answers[l] %= MOD
  return sum([(-1)**i * answers[i] for i in range(n)])

def min(a,b):
  if a<b:
    return a
  return b

T = int(raw_input())
for testcase in range(T):
  parent = {}
  children = defaultdict(set)
  servers = {}
  childrenservers = defaultdict(list)
  [M,N] = [int(x) for x in raw_input().split()]
  original = set()
  for i in range(M):
    string = raw_input()
    original.add(string)
    while string:
      next = string[:-1]
      parent[string] = next
      children[next].add(string)
      string = next
  bfs = [""]
  visited = set()
  while bfs:
    now = bfs.pop()
    if now not in visited:
      visited.add(now)
      bfs.append(now)
      for child in children[now]:
        bfs.append(child)
    else:
      if not children:
        servers[now] = 1
        if now != "":
          childrenservers[parent[now]].append(1)
      else:
        server = 0
        for child in children[now]:
          server += servers[child]
        if now in original:
          server += 1
          childrenservers[now].append(1)
        servers[now] = min(server,N)
        if now != "":
          childrenservers[parent[now]].append(min(server,N))
  probability = 1
  for node in childrenservers:
    probability *= prob(servers[node], childrenservers[node])
    probability %= MOD
  serversum = 0
  for node in servers:
    serversum += servers[node]
  print "Case #%d: %d %d"%(testcase+1,serversum, probability)
