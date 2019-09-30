import sys

T = int(sys.stdin.readline())

for t in range(1, T+1):
  veins = int(sys.stdin.readline())
  d = []
  l = []

  for _ in range(veins):
    di, li = map(int, sys.stdin.readline().strip().split())
    d.append(di)
    l.append(li)

  d.append(int(sys.stdin.readline()))
  l.append(1)
  reachable = [-1] * (veins + 1)
  reachable[0] = d[0]

  for veinI in range(veins + 1):
    upTo = d[veinI] + reachable[veinI]

    nextVein = veinI + 1
    while nextVein < veins + 1 and d[nextVein] <= upTo:
      reachable[nextVein] = max(reachable[nextVein], min(l[nextVein],
                                                         d[nextVein] - d[veinI]))
      nextVein += 1

  if reachable[veins] > 0:
    ans = 'YES'
  else:
    ans = 'NO'

  print 'Case #%d: %s' % (t, ans)
