def doit(i, j):
  if i == 0 or j == 0:
    return 0
  if j == 1:
    return 1
  if j >= i:
    return 0
  aux = 0
  for x in xrange(1, j):
    aux += A[j][x] * C[i - j - 1][j - x - 1]
    aux %= MOD
  return aux

def comb(i, j):
  if i == 0:
    if j == 0:
      return 1
    else:
      return 0
  if j > i:
    return 0
  return (C[i - 1][j - 1] + C[i - 1][j]) % MOD

f = open('c.in', 'r')
MOD = 100003
nmax = 512
A = [[0] * nmax for i in range(nmax)]
C = [[0] * nmax for i in range(nmax)]
for i in range(0, nmax):
  for j in range(0, nmax):
    C[i][j] = comb(i, j)
    A[i][j] = doit(i, j)
T = int(f.readline())
for t_no in range(1, T + 1):
  N = int(f.readline())
  sol = 0
  for i in range(1, N):
    sol += A[N][i]
    sol %= MOD
  print 'Case #%s: %s' % (t_no, sol)
