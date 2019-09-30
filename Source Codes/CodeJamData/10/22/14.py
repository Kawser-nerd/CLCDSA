import sys

cases = sys.stdin.readline()

for ii in range(0,int(cases)):
  N,K,B,T = [int(x) for x in sys.stdin.readline().split()]
  X = [int(x) for x in sys.stdin.readline().split()]
  V = [int(x) for x in sys.stdin.readline().split()]

  X.reverse()
  V.reverse()
  pocOK = 0
  pocF = 0
  res = 0
  for xi,vi in zip(X,V):
    if xi+vi*T>=B: 
      pocOK+=1
      res+=pocF
    else: pocF+=1
    if pocOK >=K: break

  if pocOK >=K:  print "Case #%d: %d" % (ii+1,res)
  else: print "Case #%d: IMPOSSIBLE" % (ii+1)

