from heapq import heappush, heappop

def mare(s1, s2):
  if len(s1) > len(s2): return True
  if len(s1) < len(s2): return False
  return s1 > s2

def add(v, s, smn, nv, i, j):
  global D, heap, MAX
  s += smn + nv
  nv = ord(nv) - ord('0')
  if smn == '+':
    v += nv
  else:
    v -= nv
  if v > 250 or v < -250: return
  if v not in D[i][j] or mare(D[i][j][v], s):
    D[i][j][v] = s
    heappush(heap, (len(s), s, v, i, j))

def are(i, j, c):
  if i > 0 and S[i-1][j] == c:
    return True
  if j > 0 and S[i][j-1] == c:
    return True
  if i + 1 < n and S[i+1][j] == c:
    return True
  if j + 1 < n and S[i][j+1] == c:
    return True
  return False

f = open('p3.in', 'r')
T = int(f.readline())
for x in range(T):
  print 'Case #%s:' % (x + 1)
  n, m = [int(x) for x in f.readline().split(' ')]
  S = [ f.readline()[:-1] for x in range(n)]
  queries = [int(x) for x in f.readline().split(' ')]
  D = []
  for x in range(n):
    D.append([{} for y in range(n)])
  heap = []
  for i in range(n):
    for j in range(n):
      if S[i][j] >= '0' and S[i][j] <= '9':
        D[i][j][ord(S[i][j]) - ord('0')] = S[i][j]
        heappush(heap, (1, S[i][j], ord(S[i][j]) - ord('0'), i, j))
  MAX = max(queries)
  while len(heap) > 0:
    ll, s, v, i, j = heappop(heap)
    if D[i][j][v] != s: continue
    if i + 2 < n:
      add(v, s, S[i+1][j], S[i+2][j], i+2, j)
    if i - 2 >= 0:
      add(v, s, S[i-1][j], S[i-2][j], i-2, j)
    if j + 2 < n:
      add(v, s, S[i][j+1], S[i][j+2], i, j+2)
    if j - 2 >= 0:
      add(v, s, S[i][j-1], S[i][j-2], i, j-2)
    if are(i, j, '+'):
      add(v, s, '+', S[i][j], i, j)
    if are(i, j, '-'):
      add(v, s, '-', S[i][j], i, j)
    if i + 1 < n and j + 1 < n:
      add(v, s , S[i][j+1], S[i+1][j+1], i+1, j+1)
      add(v, s , S[i+1][j], S[i+1][j+1], i+1, j+1)
    if i + 1 < n and j - 1 >= 0:
      add(v, s , S[i][j-1], S[i+1][j-1], i+1, j-1)
      add(v, s , S[i+1][j], S[i+1][j-1], i+1, j-1)
    if i - 1 >= 0 and j - 1 >= 0:
      add(v, s , S[i][j-1], S[i-1][j-1], i-1, j-1)
      add(v, s , S[i-1][j], S[i-1][j-1], i-1, j-1)
    if i - 1 >= 0 and j + 1 < n:
      add(v, s , S[i][j+1], S[i-1][j+1], i-1, j+1)
      add(v, s , S[i-1][j], S[i-1][j+1], i-1, j+1)
  for query in queries:
    sol = ''
    for i in range(n):
      for j in range(n):
        if query in D[i][j]:
          if sol == '' or mare(sol, D[i][j][query]):
            sol = D[i][j][query]
    print sol
