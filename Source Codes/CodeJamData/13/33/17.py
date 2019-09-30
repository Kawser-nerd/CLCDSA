from collections import deque

att = {}

def init():
  d, n, w, e, s, dd, dp, ds = (int(elm) for elm in raw_input("").split())
  for i in range(n):
    if d not in att: att[d] = []
    att[d].append((w, e, s))
    d += dd
    w += dp
    e += dp
    s += ds

def cal():
  wall = {}
  for i in range(-500, 500): wall[i] = 0
  res = 0
  mx = 0
  for d, lst in att.iteritems():
    mx = max(mx, d)
  for d in range(mx + 1):
    if d not in att: continue
    for (w, e, s) in att[d]:
      cnt = 0
      for p in range(w, e):
        if wall[p] < s: cnt += 1
      if cnt: res += 1
    for (w, e, s) in att[d]:
      for p in range(w, e):
        wall[p] = max(wall[p], s)
  return res

T = int(raw_input(""))
for i in range(1, T + 1):
  att = {}
  n = int(raw_input(""))
  for j in range(n): init()
  res = cal()
  print 'Case #%d: %s' % (i, res)