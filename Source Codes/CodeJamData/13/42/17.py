from sys import stdin

T = int(stdin.readline())
for _ in xrange(1, T+1):
  N, P = map(int, stdin.readline().split())
  if P == pow(2, N):
    a = pow(2,N)-1
    b = a
  else:
    k = N
    while pow(2,N) - pow(2,N-k) >= P: k -= 1
    a = 2*(pow(2,k) - 1)

    k = N
    while pow(2,k) - 1 >= P: k -= 1
    b = pow(2,N) - pow(2,N-k)
  print 'Case #%d: %d %d' % (_, a, b)
