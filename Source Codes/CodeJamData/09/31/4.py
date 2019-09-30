
def main(inp):
  T = int(inp.readline())
  for i in xrange(1, T+1):
    line = inp.readline().strip()
    digs = list(line)
    base = max([2, len(set(digs))])
    vals = {}
    vals[digs[0]] = 1
    val = 0
    for d in digs:
      if d not in vals:
        vals[d] = val
        val += 1
        if val == 1:
          val = 2
    ans = 0
    for d in digs:
      ans *= base
      ans += vals[d]
    print "Case #%s: %s" % (i, ans)

if __name__ == "__main__":
  import sys
  main(sys.stdin)
