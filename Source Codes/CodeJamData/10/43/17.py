f = open('c.in', 'r')
T = int(f.readline())
for t_no in range(T):
  n = int(f.readline())
  P = []
  A = [[0] * 102 for x in range(102)]
  for ii in range(n):
    x1, y1, x2, y2 = [int(x) for x in f.readline().split()]
    for i in xrange(x1, x2 + 1):
      for j in xrange(y1, y2 + 1):
        A[i + 1][j + 1] = 1
  sol = 0
  while sum([sum(x) for x in A]) > 0:
    B = [[0] * 102 for x in range(102)]
    for i in range(1, 102):
      for j in range(1, 102):
        if A[i][j] == 1 and A[i - 1][j] + A[i][j - 1] > 0:
            B[i][j] = 1
        elif A[i - 1][j] + A[i][j - 1] == 2:
            B[i][j] = 1
    A = B
    sol += 1
  print 'Case #%s: %s' % (t_no + 1, sol)
