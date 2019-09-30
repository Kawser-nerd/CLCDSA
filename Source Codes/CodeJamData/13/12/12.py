import sys

def main():
  nc = int(sys.stdin.next())
  for cNum in xrange(1, 1+nc):
    e, r, n = map(int, sys.stdin.next().split())
    vs = map(int, sys.stdin.next().split())

    best = [0]*(e+1)
    for v in vs:
      nxtB = [0]*(e+1)
      for i in xrange(e+1):
        for k in xrange(i+1):
          remE = min(i-k+r, e)
          nxtB[remE] = max(nxtB[remE], best[i] + k*v)
      best = nxtB

    print "Case #{0}: {1}".format(cNum, max(best))

if __name__=="__main__": sys.exit(main())

