import sys
import re

T = int(sys.stdin.readline().strip())
for t in xrange(T):
  D = [int(a) for a in re.split("\s+", sys.stdin.readline().strip())]
  (L,B,N,C) = D[:4]
  D_ = D[4:]
  D = []

  J = int(N/C)
  for j in xrange(J):
    D.extend(D_)
  for i in xrange(N-len(D)):
    D.append(D_[i])

  # Find first star that benefits from boosters
  cur = 0
  for f in xrange(len(D)):
    if cur + 2 * D[f] > B: break
    cur += 2 * D[f]

  # Calculate benefits
  F = [(cur + 2 * D[f] - B) / 2]
  F.extend(D[(f+1):])

  print "Case #%d: %d" % (t+1, 2*sum(D)-sum(sorted(F,reverse=True)[:L]))

