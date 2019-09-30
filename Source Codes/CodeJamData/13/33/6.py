import collections
import sys
inp = sys.stdin

T = int(inp.readline())
for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  N = int(inp.readline())
  attacks = collections.defaultdict(list)
  for _ in xrange(N):
    d, n, w, e, s, delta_d, delta_p, delta_s = map(int, inp.readline().split())
    for i in xrange(n):
      attacks[d+delta_d*i].append((w+delta_p*i, e+delta_p*i, s+delta_s*i))
  wall = collections.defaultdict(int)
  ans = 0
  for i in xrange(676060+1):
    if i not in attacks:
      continue
    nwall = wall.copy()
    for w, e, s in attacks[i]:
      failed = False
      for x in xrange(w, e):
        if wall[x] < s:
          failed = True
          nwall[x] = max(nwall[x], s)
      if failed:
        ans += 1
    wall = nwall
  print ans
