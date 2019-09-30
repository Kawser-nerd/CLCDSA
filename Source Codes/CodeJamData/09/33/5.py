
def main(inp):
  T = int(inp.readline())
  for z in xrange(1, T+1):
    P, Q = (int(x.strip()) for x in inp.readline().split(' '))
    rels = [0] + [int(x.strip()) for x in inp.readline().split(' ')] + [P+1]
    dp = [{i+1: 0} for i in xrange(Q+1)]
    for i in xrange(1, Q+1):
      for j in xrange(Q-i+1):
        cm = 2**100
        c = rels[j+i+1] - rels[j] - 2
        for k in xrange(j+1, j+1+i):
          cm = min(cm, c + dp[j][k] + dp[k][j+i+1])
        dp[j][j+i+1] = cm
    print "Case #%s: %s" % (z, dp[0][Q+1])

if __name__ == "__main__":
  import sys
  main(sys.stdin)
