from math import sqrt

T = int(raw_input())

def is_square(x):
  y = int(sqrt(x) + 0.1)
  return y*y == x

def try_it(s, i):
  global poss
  if i >= len(poss):
    return s if is_square(s) else 0
  else:
    p = poss[i]
    x = try_it(s, i+1)
    if x:
      return x
    return try_it(s+p, i+1)


for case_num in xrange(1, T + 1):
  S = raw_input().strip()
  N = len(S)
  poss = []
  s = 0
  for i in xrange(N):
    c = S[i]
    power = N - 1 - i
    if c == '1':
      s += 2 ** power
    elif c == '?':
      poss.append(2 ** power)
  res = try_it(s, 0)
  output = ''
  while res:
    output = str(res % 2) + output
    res /= 2

  print "Case #%d: %s" % (case_num, output)
