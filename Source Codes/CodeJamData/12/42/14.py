#!/usr/bin/python

import sys

T = int(sys.stdin.readline())

def fill(W, L, r):
  x = -1
  y = -1
  res = []
  last = None
  poses = []
  while (len(r) > 0):
    xres = []
    while (x == -1 or x + r[0][0] <= W):
      c = r.pop(0)
      current = c[0]
      poses.append(c[1])
      if (x == -1):
        x = current
      else:
        x += 2*current
      #print "dasx"
      #print x
      xres.append(x - current)
      #print xres
      last = current
      if len(r) == 0:
        break
    #print "enditer"
    #print xres
    lasty = y
    x = -1
    if y == -1:
      res += [(x, 0) for x in xres]
      y = last
    else:
      res += [(x, y + last) for x in xres]
      y += 2*last
  assert(lasty <= L)
  return zip(poses, res)

for i in range(T):
  lin = sys.stdin.readline().strip().split()
  N = int(lin.pop(0))
  W = int(lin.pop(0))
  L = int(lin.pop(0))
  r = []
  lin = sys.stdin.readline().strip().split()
  for j in range(N):
    r.append((int(lin.pop(0)), j))
  r.sort()
  ress = fill(W, L, r)
  ress.sort()
  #print ress
  resss = [list([str(y) for y in x[1]]) for x in ress]
  full = sum(resss, [])
  print "Case #" + str(i+1) + ": " + ' '.join(full)



