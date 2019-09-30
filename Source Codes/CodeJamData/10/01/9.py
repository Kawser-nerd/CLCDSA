T = int(raw_input())
def isSnapperOn(n, k):
  return (k / (2 ** n))%2 == 1
def isLightOn(n, k):
  return all(isSnapperOn(i, k) for i in xrange(n))
for case in xrange(1, T + 1):
  N, K = [int(x) for x in raw_input().split()]
  print "Case #" + str(case) + ":", "ON" if isLightOn(N,K) else "OFF"
