#!/usr/bin/python3

def dfs(e, ma, u, v):
  if v in u:
    return False
  u[v] = True
  for x in e[v]:
    if (not x in ma) or dfs(e, ma, u, ma[x]):
      ma[x] = v
      return True
  return False

def solve():
  n = int(input())
  e = {}
  av = {}
  bv = {}
  ac = 0
  bc = 0
  for i in range(n):
    a, b = list(input().split())
    if not a in e:
      e[a] = []
    e[a].append(b)
    if not a in av:
      av[a] = True
      ac += 1
    if not b in bv:
      bv[b] = True
      bc += 1
  m = 0
  ma = {}
  for a in av:
    u = {}
    if dfs(e, ma, u, a):
      m += 1
  return str(n - (ac + bc - m))

nt = int(input())
for tt in range(nt):
  print('Case #' + str(tt + 1) + ': ' + str(solve()))
