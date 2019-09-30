from collections import deque

import sys
inp = sys.stdin

T = int(inp.readline())
for cas in xrange(1, T+1):
  R, K, N = (int(x) for x in inp.readline().split(' '))
  print "Case #%d:" % (cas),
  ts = deque(int(x) for x in inp.readline().split(' '))
  tmp = deque()
  r = 0
  runs = [None]*N
  eurs = [0]*N
  cur = 0
  runs[0] = 0
  cycled = False
  tot = 0
  while r < R:
    r += 1
    tmp.clear()
    tt = 0
    while ts and tt < K:
      t = ts.popleft()
      if tt + t > K:
        ts.appendleft(t)
        break
      tt += t
      tmp.append(t)
    tot += tt
    cur = (cur + len(tmp))%N
    if not cycled and runs[cur] is not None:
      c_runs = r - runs[cur]
      c_eurs = tot - eurs[cur]
      c_num = (R-r) / c_runs
      tot += c_eurs*c_num
      r += c_num*c_runs
      cycled = True
    runs[cur] = r
    eurs[cur] = tot
    ts.extend(tmp)
  print tot
