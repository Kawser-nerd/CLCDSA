import sys
inp = sys.stdin

T = int(inp.readline())
for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  X, Y = map(int, inp.readline().split())
  ans = ''
  if X < 0:
    ans += 'EW' * -X
  elif X > 0:
    ans += 'WE' * X
  if Y < 0:
    ans += 'NS' * -Y
  elif Y > 0:
    ans += 'SN' * Y
  print ans
