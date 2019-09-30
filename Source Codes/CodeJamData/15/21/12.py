import sys
sys.setrecursionlimit(10000)

tc = int(sys.stdin.readline())
maxN = 1000
bests = [ None ] * (maxN + 1)
bests[1] = 1
for N in xrange(2, maxN+1):
  strN = str(N)
  revN = int(''.join(reversed(strN)))
  if revN < N and strN[-1] != '0':
    bests[N] = min(bests[N-1], bests[revN]) + 1
  else:
    bests[N] = bests[N-1] + 1

cache = {}
def walk(N):
  if N <= maxN: return bests[N]
  if N in cache: return cache[N]
  if N % 10 == 0: return 1 + walk(N-1)
  d = 1
  ten = 10
  while ten < N:
    d += 1
    ten *= 10
  t = 10**(d-1) - 1
  res_t = walk(t)
  res = N - t + res_t
  ten = 1
  while ten < N:
    target = (N / ten) * ten + 1
    if target <= N:
      revTarget = int(''.join(reversed(str(target))))
      res = min(res, res_t + N - target + 1 + revTarget - t)
    ten *= 10
  cache[N] = res
  return res

for tmp_tc in xrange(tc):
  [ N ] = map(lambda x: int(x), sys.stdin.readline().split(' '))
  print "Case #%d: %d" % (1+tmp_tc, walk(N))
