z = input()

from math import factorial as fac
ocle = fac(37)

for cas in xrange(1,z+1):
  b, n = map(int,raw_input().strip().split())
  x = map(int,raw_input().strip().split())
  x += [0] * (37 - n)
  x.sort()
  cx = list(x)
  sx = sum(x)
  mx = x[-1]
  for i in xrange(1,37):
    crem = x[i-1] * i - sum(x[:i])
    if b >= crem:
      cx.append(x[i-1]+(b-crem)/i)
  cx = cx + [y - 1 for y in cx if y]
  cx = cx + [y + 1 for y in cx]

  cx = sorted(set(cx))
#  cx = range(5000)
  best = 0
#  print x
#  print cx
  for v in cx:
    cle = sum(1 for w in x if w <= v)
    req = cle * v - sum(w for w in x if w <= v)
    if req <= b and cle:
      for j in xrange(cle):
        if req + j <= b:
          bag = ((cle-j)*v - sum(x[:cle-j])) * 36 * ocle / (cle - j) - (req + j) * ocle
          best = max(best, bag)
  best = float(best) / ocle
  print 'Case #%d: %.15f' % (cas, best)

