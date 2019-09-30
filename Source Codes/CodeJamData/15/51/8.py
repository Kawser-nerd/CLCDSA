import sys
import itertools
sys.setrecursionlimit(10000)

tc = int(sys.stdin.readline().strip())

for tmp_tc in xrange(tc):
  [ N, D ] = map(lambda x: int(x), sys.stdin.readline().strip().split(' '))
  [ S0, AS, CS, RS ] = map(lambda x: int(x), sys.stdin.readline().strip().split(' '))
  [ M0, AM, CM, RM ] = map(lambda x: int(x), sys.stdin.readline().strip().split(' '))

  currentS, currentM = S0, M0
  S, M = [ S0 ], [ None ]
  edges = {}
  for i in xrange(1, N):
    currentS = (currentS * AS + CS) % RS
    currentM = (currentM * AM + CM) % RM
    S.append(currentS)
    M.append(currentM % i)
    edges[currentM % i] = edges.get(currentM % i, []) + [ i ]

  cnt = [ 0 ] * N

  def walk_cnt(node):
    res = 1
    for n in edges.get(node, []):
      res += walk_cnt(n)
    cnt[node] = res
    return res

  walk_cnt(0)

  def walk(node, minS, maxS):
    if S[node] < minS or S[node] > maxS: return cnt[node]
    res = 0
    for n in edges.get(node, []):
      res += walk(n, minS, maxS)
    return res

  res = None
  for minS in xrange(S0 - D, S0 + 1):
    maxS = minS + D
    tmp = walk(0, minS, maxS)
    if res == None or tmp < res: res = tmp
  res = N - res
  print "Case #%d: %d" % (1+tmp_tc, res)

