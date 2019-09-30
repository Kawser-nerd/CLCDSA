from collections import defaultdict
from random import randint

def spt(s):
  lst = []
  p, c = s[0], 1
  for e in s[1:]:
    if p != e:
      lst.append((p, c))
      p, c = e, 1
    else:
      c += 1
  lst.append((p, c))
  # print lst
  return lst

def chk(sts):
  de = [tpl[0] for tpl in sts[0]]
  for e in sts[1:]:
    de2 = [tpl[0] for tpl in e]
    if de != de2:
      return False
  return True

def cal(lst):
  res = 1000000000000000000000000000000000000000000000000000
  for i in xrange(1, max(lst) + 1):
    tmp = 0
    for e in lst:
      tmp += abs(e - i)
    res = min(res, tmp)
  return res

def solve(tcase):
  n = int(raw_input(''))
  sts = [spt(raw_input('')) for i in xrange(n)]
  if not chk(sts):
    print 'Case #%d: Fegla Won' % tcase
    return
  res = 0
  sz = len(sts[0])
  for i in xrange(sz):
    nm = [sts[j][i][1] for j in xrange(n)]
    nm = sorted(nm)
    res += cal(nm)
  print 'Case #%d: %d' % (tcase, res)

T = int(raw_input(''))
for tcase in xrange(1, T + 1):
  solve(tcase)