import sys

def f(a, sizes):
  sizes.sort()
  len_ = len(sizes)
  res = len_
  nb = 0
  for i, s in enumerate(sizes):
    while a <= s:
      a += a-1
      nb += 1
      if nb > res: break
    if nb > res: break
    res = min(res, nb + len_ - i - 1)
    a += s
  return res

samples = int(sys.stdin.readline().rstrip())
for i in range(samples):
  [a, n] = sys.stdin.readline().rstrip().split()
  sizes = sys.stdin.readline().rstrip().split()
  a = int(a)
  sizes = map(lambda x: int(x), sizes)
  print "Case #%d: %s" % (i+1, f(a, sizes))
