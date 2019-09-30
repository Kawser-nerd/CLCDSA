from sys import stdin as inp
import math


def min_r(a, b):
  angle = math.atan2(a[1]-b[1], a[0]-b[0])
  cos = math.cos(angle)
  if a[0] == b[0]:
    miny = min(a[1]-a[2], b[1]-b[2])
    maxy = max(a[1]+a[2], b[1]+b[2])
    return (maxy-miny)/2.0
  else:
    if cos < 0: cos = -cos
    minx = min(a[0]-a[2]*cos, b[0]-b[2]*cos)
    maxx = max(a[0]+a[2]*cos, b[0]+b[2]*cos)
    return (maxx-minx)/cos/2.0


T = int(inp.readline())
for z in xrange(1, T+1):
  N = int(inp.readline())
  plants = []
  for i in xrange(N):
    plants.append([int(x) for x in inp.readline().split()])
  if N <= 2:
    ans = max(plant[2] for plant in plants)
  else:
    ans = max(plants[0][2], min_r(plants[1], plants[2]))
    ans = min(ans, max(plants[1][2], min_r(plants[0], plants[2])))
    ans = min(ans, max(plants[2][2], min_r(plants[0], plants[1])))
  print "Case #%s: %.8f" % (z, ans)
