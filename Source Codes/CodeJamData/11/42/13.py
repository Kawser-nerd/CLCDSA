import sys

T = int(sys.stdin.readline())
for no_t in xrange(1, T + 1):
  N, M, D = [int(x) for x in sys.stdin.readline().split()]
  A = [[int(x) for x in sys.stdin.readline().strip()] for x in xrange(N)]
  sol = 0
  sumx = [[0] * M for x in xrange(N)]
  sumy = [[0] * M for x in xrange(N)]
  nr = [[0] * M for x in xrange(N)]
  for i in xrange(N):
    for j in xrange(M):
      sumx[i][j] = i * (D + A[i][j])
      sumy[i][j] = j * (D + A[i][j])
      nr[i][j] = D + A[i][j]
      if i:
        sumx[i][j] += sumx[i - 1][j]
        sumy[i][j] += sumy[i - 1][j]
        nr[i][j] += nr[i - 1][j]
      if j:
        sumx[i][j] += sumx[i][j - 1]
        sumy[i][j] += sumy[i][j - 1]
        nr[i][j] += nr[i][j - 1]
      if i and j:
        sumx[i][j] -= sumx[i - 1][j - 1]
        sumy[i][j] -= sumy[i - 1][j - 1]
        nr[i][j] -= nr[i - 1][j - 1]
  sol = 0
  for k in xrange(min(N, M), 2, -1):
    if sol:
      break
    for i in xrange(k - 1, N):
      for j in xrange(k - 1, M):
        auxx = sumx[i][j]
        auxy = sumy[i][j]
        auxn = nr[i][j]
        if(i - k >= 0):
          auxx -= sumx[i - k][j]
          auxy -= sumy[i - k][j]
          auxn -= nr[i - k][j]
        if(j - k >= 0):
          auxx -= sumx[i][j- k]
          auxy -= sumy[i][j - k]
          auxn -= nr[i][j - k]
        if (i - k >= 0) and (j - k >= 0):
          auxx += sumx[i - k][j- k]
          auxy += sumy[i - k][j - k]
          auxn += nr[i - k][j - k]
        auxx -= A[i][j] * i + A[i - k + 1][j] * (i - k + 1) + A[i][j - k + 1] * i + A[i - k + 1][j - k + 1] * (i - k + 1)
        auxy -= A[i][j] * j + A[i - k + 1][j] * j + A[i][j - k + 1] * (j - k + 1) + A[i - k + 1][j - k + 1] * (j - k + 1)
        auxn -= A[i][j] + A[i - k + 1][j] + A[i][j - k + 1] + A[i - k + 1][j - k + 1]
        if auxx * 2 == auxn * (i + i - k + 1) and auxy * 2 == auxn * (j + j - k + 1):
          sol = k
    if sol:
      print 'Case #%s: %s' % (no_t, k)
  if not sol:
    print 'Case #%s: IMPOSSIBLE' % no_t
