#!/usr/bin/python3

def better(c, j, aC, aJ):
  if aC == '-1':
    return True
  if abs(int(aC) - int(aJ)) != abs(int(c) - int(j)):
    return abs(int(aC) - int(aJ)) > abs(int(c) - int(j))
  if int(aC) != int(c):
    return int(aC) > int(c)
  if int(aJ) != int(j):
    return int(aJ) > int(j)
  return False

def getMax(s):
  res = ''
  for x in s:
    if x == '?':
      res += '9'
    else:
      res += x
  return res

def getMin(s):
  res = ''
  for x in s:
    if x == '?':
      res += '0'
    else:
      res += x
  return res

def solve():
  C, J = list(input().split())
  aC, aJ = '-1', '-1'
  n = len(C)
  for eq in range(n + 1):
    # we have eq equal highest digits
    c0 = ''
    j0 = ''
    ok = True
    for i in range(eq):
      if C[i] != '?' and J[i] != '?' and C[i] != J[i]:
        ok = False
        break
      if C[i] != '?':
        c0 += C[i]
        j0 += C[i]
      elif J[i] != '?':
        c0 += J[i]
        j0 += J[i]
      else:
        c0 += '0'
        j0 += '0'
    if not ok:
      continue
    if eq == n:
      if better(c0, j0, aC, aJ):
        aC, aJ = c0, j0
      continue
    # eq-th digit to search...
    for dc in range(10):
      dcs = str(dc)
      if C[eq] != '?' and C[eq] != dcs:
        continue
      for dj in range(10):
        djs = str(dj)
        if J[eq] != '?' and J[eq] != djs:
          continue
        if dcs == djs:
          continue
        if dc < dj:
          c1 = dcs + getMax(C[eq + 1:])
          j1 = djs + getMin(J[eq + 1:])
        else:
          c1 = dcs + getMin(C[eq + 1:])
          j1 = djs + getMax(J[eq + 1:])
        if better(c0 + c1, j0 + j1, aC, aJ):
          aC, aJ = c0 + c1, j0 + j1
  return aC + ' ' + aJ

nt = int(input())
for tt in range(nt):
  print('Case #' + str(tt + 1) + ': ' + str(solve()))
