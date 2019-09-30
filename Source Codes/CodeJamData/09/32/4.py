
def main(inp):
  T = int(inp.readline())
  for z in xrange(1, T+1):
    pts = int(inp.readline())
    vals = [0 for i in xrange(6)]
    for i in xrange(pts):
      vs = [int(x.strip()) for x in inp.readline().split(' ')]
      for i, v in enumerate(vs):
        vals[i] += v
    for i, v in enumerate(vals):
      vals[i] = v*1.0/pts
    a = vals[3]*vals[3] + vals[4]*vals[4] + vals[5]*vals[5]
    b = vals[0]*vals[3] + vals[1]*vals[4] + vals[2]*vals[5]
    c = vals[0]*vals[0] + vals[1]*vals[1] + vals[2]*vals[2]
    if a != 0:
      tm = max([0, -b/a])
    else:
      tm = 0
    dm = max([0, (a * tm*tm + 2*b*tm + c)]) ** 0.5
    print "Case #%s: %.8f %.8f" % (z, dm, tm)

if __name__ == "__main__":
  import sys
  main(sys.stdin)
