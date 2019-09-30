#!/usr/bin/python

rl = raw_input

def add(v, newvalues, ind, x, y):
  d = int(y) if x == '+' else -int(y)
  for thing in v:
    if (thing+d not in newvalues[ind]) or (newvalues[ind][thing+d] > v[thing] + x + y):
      newvalues[ind][thing+d] = v[thing] + x + y

T = int(rl())
for cas in xrange(1,T+1):
  W,Q = map(int,rl().split())
  X = [rl() for i in xrange(W)]
  values = {}
  for i in xrange(W):
    for j in xrange(W):
      if "0" <= X[i][j] <= "9":
        values[i,j] = {int(X[i][j]):X[i][j]}
  queries = {}
  for a,b in enumerate(rl().split()):
    queries[int(b)] = a
  ans = ["Z"] * Q
  while queries:
    remv = set()
    newvalues = {}
    for i,j in values:
      newvalues[i,j] = {}
      for q in queries:
        if q in values[i,j] and values[i,j][q] < ans[queries[q]]:
          ans[queries[q]] = values[i,j][q]
          remv.add(q)
    for i,j in values:
      if i > 1: add(values[i,j], newvalues, (i-2,j), X[i-1][j], X[i-2][j])
      if j > 1: add(values[i,j], newvalues, (i,j-2), X[i][j-1], X[i][j-2])
      if i < W-2: add(values[i,j], newvalues, (i+2,j), X[i+1][j], X[i+2][j])
      if j < W-2: add(values[i,j], newvalues, (i,j+2), X[i][j+1], X[i][j+2])
      if i > 0 and j > 0:
        add(values[i,j], newvalues, (i-1,j-1), X[i-1][j], X[i-1][j-1])
        add(values[i,j], newvalues, (i-1,j-1), X[i][j-1], X[i-1][j-1])
      if i > 0 and j < W-1:
        add(values[i,j], newvalues, (i-1,j+1), X[i-1][j], X[i-1][j+1])
        add(values[i,j], newvalues, (i-1,j+1), X[i][j+1], X[i-1][j+1])
      if i < W-1 and j > 0:
        add(values[i,j], newvalues, (i+1,j-1), X[i+1][j], X[i+1][j-1])
        add(values[i,j], newvalues, (i+1,j-1), X[i][j-1], X[i+1][j-1])
      if i < W-1 and j < W-1:
        add(values[i,j], newvalues, (i+1,j+1), X[i+1][j], X[i+1][j+1])
        add(values[i,j], newvalues, (i+1,j+1), X[i][j+1], X[i+1][j+1])
      if i > 0: add(values[i,j], newvalues, (i,j), X[i-1][j], X[i][j])
      if j > 0: add(values[i,j], newvalues, (i,j), X[i][j-1], X[i][j])
      if i < W-1: add(values[i,j], newvalues, (i,j), X[i+1][j], X[i][j])
      if j < W-1: add(values[i,j], newvalues, (i,j), X[i][j+1], X[i][j])

    values = newvalues
 
    for q in remv:
      del queries[q]
  print "Case #%d:" % cas
  for a in ans:
    print a

