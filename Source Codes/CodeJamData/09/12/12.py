import sys

class Map(object):

  def __init__(self, N, M):
    self.n = N
    self.m = M
    self.lights = {}

  def AddIntersection(self, row, column, s, w, t):
    if t > s + w:
      t -= ((s + w) + 1)/ t * (s + w)
    self.lights[row, column] = (s, w, t)

  def GetNextLightCycles(self, x, y, t):
    x /= 2
    y /= 2
    s, w, t0 = self.lights[x, y]
    diff = t - t0
    full_cycles = diff / (s + w)
    dt = diff - full_cycles * (s + w)

    if dt < s:
      return {"s": 0, "w": s - dt}
    if dt < s + w:
      return {"w": 0, "s": s + w - dt}
    assert False

  def PossibleDirections(self, x, y, t):
    candidates = []
    if x < 2 * self.n - 1: # south
      if x % 2 == 1: # block walk
        candidates.append((x + 1, y, t + 2))
      else: # traffic light
        candidates.append((x + 1, y, t + 1 + self.GetNextLightCycles(x, y,
                                                                     t)["s"]))
    if x > 0: # north
      if x % 2 == 0: # block walk
        candidates.append((x - 1, y, t + 2))
      else:
        candidates.append((x - 1, y, t + 1 + self.GetNextLightCycles(x, y,
                                                                    t)["s"]))
    if y < 2 * self.m - 1: # east
      if y % 2 == 1: # block walk
        candidates.append((x, y + 1, t + 2))
      else:
        candidates.append((x, y + 1, t + 1 + self.GetNextLightCycles(x, y,
                                                                     t)["w"]))
    if y > 0: # west
      if y % 2 == 0: # block walk
        candidates.append((x, y - 1, t + 2))
      else:
        candidates.append((x, y - 1, t + 1 + self.GetNextLightCycles(x, y,
                                                                     t)["w"]))
    return candidates


def WalkTo(the_map, field, x, y):
  t = field[x, y]
  #print "I'm at %d/%d at %d" % (x, y, t)
  candidates = the_map.PossibleDirections(x, y, t)
  for c in candidates:
    target = field[c[0], c[1]]
    if target < 0 or c[2] < target:
      field[c[0], c[1]] = c[2]
      WalkTo(the_map, field, c[0], c[1])


C = int(sys.stdin.readline())
for c in range(C):
  N, M = tuple(int(x) for x in sys.stdin.readline().split())
  the_map = Map(N, M)

  for n in range(N):
    numbers = list(int(x) for x in sys.stdin.readline().split())
    for m in range(M):
      s, w, t = numbers[:3]
      del numbers[:3]
      the_map.AddIntersection(n, m, s, w, t)

    assert not numbers

  field = {}
  for x in range(2 * N):
    for y in range(2 * M):
      field[x, y] = -1
  field[2 * N - 1, 0] = 0
  WalkTo(the_map, field, 2 * N - 1, 0)

  print "Case #%d: %d" % (c + 1, field[0, 2 * M -1])
