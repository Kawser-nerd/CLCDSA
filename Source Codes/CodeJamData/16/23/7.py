import itertools
from scipy.optimize import linprog

def solve():
  N = input()
  words = []
  w1s = set()
  w2s = set()

  for i in xrange(N):
    w1, w2 = raw_input().strip().split()
    words += [(w1, w2)]
    w1s.add(w1)
    w2s.add(w2)

  c = [1] * N

  A = []

  for w1 in w1s:
    row = [0] * N
    for i in xrange(N):
      if w1 == words[i][0]:
        row[i] = -1
    A += [row]
  for w2 in w2s:
    row = [0] * N
    for i in xrange(N):
      if w2 == words[i][1]:
        row[i] = -1
    A += [row]

  b = [-1] * len(A)

  res = linprog(c, A, b, bounds = (0, 1), options={'disp': False, 'bland': False, 'tol': 1e-12, 'maxiter': 100000000})
  #print res
  return N - sum(res.x)

T = input()
for i in range(T):
  print 'Case #%d: %d' % (i+1, solve())
