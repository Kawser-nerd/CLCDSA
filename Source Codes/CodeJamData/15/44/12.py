import sys
import itertools
sys.setrecursionlimit(10000)
MOD = 1000000007

tc = int(sys.stdin.readline().strip())

for tmp_tc in xrange(tc):
  [ R, C ] = map(lambda x: int(x), sys.stdin.readline().strip().split(' '))

  def s3(r, rep):
    if r == 0: return 1
    if r == 1: return 0
    return s2(r-2, rep)

  def s2(r, rep):
    if r == 0: return 1
    res = s3(r-1, rep)
    if 2 <= r and C % 6 == 0:
      if rep == 0: res += s3(r-2, 6)
      elif rep == 3: res += s3(r-2, 6) * 3
      else: res += s3(r-2, 6) * 6
    if 2 <= r and C % 3 == 0:
      if rep == 0: res += s3(r-2, 3)
      elif rep == 3: res += s3(r-2, 3) * 3
      else: res += s3(r-2, 6) * 3
    if 3 <= r and C % 4 == 0:
      res += s3(r-3, 4) * (4 if rep == 4 else 1)
    return res % MOD

  res = (s3(R, 0) + s2(R, 0)) % MOD
  print "Case #%d: %d" % (1+tmp_tc, res)

