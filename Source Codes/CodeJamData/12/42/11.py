import sys

T = int(sys.stdin.readline())

for t in range(1, T+1):
  N, W, L = map(int, sys.stdin.readline().strip().split())
  radsr = map(int, sys.stdin.readline().strip().split())


  rads = []
  for i, r in enumerate(radsr):
    rads.append((r, i))

  rads.sort()
  rads.reverse()
  cand = [(-rads[0][0], -rads[0][0])]

  pos = []
  anspos = [(0,0)] * N

  for (r, rind) in rads:
    for i in range(len(cand)):
      (cx, cy) = cand[i]
      x = max(cx + r, 0)
      y = max(cy + r, 0)

      #print 'x,y', x, y

      if 0 <= x and 0 <= y and x <= W and y <= L:
        found = True
        for i in range(len(pos)):
          px, py = pos[i]
          if abs(px - x) < r + rads[i][0] and abs(y - py) < r + rads[i][0]:
            found = False
            break

        if found:
          pos.append((x, y))
          anspos[rind] = (x, y)
          #del cand[i]
          cand = [(x + r, y - r)] + cand + [(x - r, y + r)]
          #print cand
          break
    else:
      print 'NOT FOUND!'


  print 'Case #%d:' % t,
  for x, y in anspos:
    print x,y,
  print ''

