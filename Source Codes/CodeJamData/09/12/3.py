import heapq


def go(N,M,R):
  P = []
  C = {}
  H = {}
  start = (0, 2*N-1, 0)
  heapq.heappush(P,start)
  H[start] = 1

  #print R
  for row in R:
    for i,(s,w,t) in enumerate(row):
      row[i] = s,w, (t % (s+w))

  while P:
    t,n,m = heapq.heappop(P)
    del H[(t,n,m)]
    if n==0 and m==2*M-1: return t
    if n < 0: continue
    if m < 0: continue
    if n >= 2*N: continue
    if m >= 2*M: continue
    if C.setdefault((n,m),t) < t: 
      continue
    #print t, n, m

    def getcycle(t, t0, s, w):
      k0 = (t-t0)/(s+w)
      c0 = t0 + k0 * (s+w)
      return c0

    def push(P, x):
      if not x in H:
        heapq.heappush(P, x)
      H[x] = 1

    s, w, t0 = R[n/2][m/2]
    if n%2==1: # south of a street. go south or cross north
      k0 = getcycle(t, t0, s, w)
      k1 = k0 + s # end of light
      if k1 < t+1: k0 += s+w
      push(P, (t+2, n+1, m))
      push(P, (max(k0,t)+1,n-1, m))

    else: # north of a street. go north or cross south
      k0 = getcycle(t, t0, s, w)
      k1 = k0 + s
      if k1 < t+1: k0 += s+w
      push(P, (t+2, n-1, m))
      push(P, (max(k0,t)+1,n+1, m))

    if m%2==1: # east of a street. go east or cross west
      k0 = getcycle(t, t0, s, w) + s
      k1 = k0 + w
      if k1 < t+1: k0 += s+w
      push(P, (t+2, n, m+1))
      push(P, (max(k0,t)+1,n, m-1))

    else: # west of a street. go west or cross east
      k0 = getcycle(t, t0, s, w) + s
      k1 = k0 + w
      if k1 < t+1: k0 += s+w
      #print 'k',k0,
      push(P, (t+2, n, m-1))
      push(P, (max(k0,t)+1,n, m+1))

    #print

  return -1


import sys
C=int(sys.stdin.readline())
for c in xrange(C):
  N,M=map(int,sys.stdin.readline().split())
  R=[map(int,sys.stdin.readline().split()) for i in xrange(N)]
  R=[zip(R[i][::3], R[i][1::3], R[i][2::3]) for i in xrange(N)]
  print 'Case #%d: %d' % (c+1, go(N,M,R))

