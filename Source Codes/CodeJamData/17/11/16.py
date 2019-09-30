_T = int(raw_input())
for _t in range(1, _T+1):
  R, C = map(int, raw_input().split())
  G = []
  for _ in range(R):
    G.append(list(raw_input()))

  lasti = -1
  for i in range(R):
    lastj = -1
    for j in range(C):
      if G[i][j] != '?':
        for k in range(j-1, lastj, -1):
          G[i][k] = G[i][j]
        lastj = j
    if lastj > -1:
      for k in range(C-1, lastj, -1):
        G[i][k] = G[i][lastj]
      for k in range(i-1, lasti, -1):
        G[k] = G[i]
      lasti = i
  for k in range(R-1, lasti, -1):
    G[k] = G[lasti]
  
  print 'Case #{}:'.format(_t)
  for l in G:
    print ''.join(l)
