import sys,string
def domap(t):
  letters = list(string.letters)
  H,W=map(int,sys.stdin.readline().split())
  G = [map(int,sys.stdin.readline().split()) for i in xrange(H)]
  L,B = {},{}
  def getbasin(h,w):
    if (h,w) in B: return B[h,w]
    e = G[h][w]
    d = (h,w)
    for dh,dw in [(-1,0),(0,-1),(0,1),(1,0)]:
      if not (0 <= (h+dh) < H): continue
      if not (0 <= (w+dw) < W): continue
      de = G[h+dh][w+dw]
      if de < e: 
        d = getbasin(h+dh, w+dw)
        e = de
    B[h,w] = d
    return d
  print 'Case #%d:' % (t+1)
  for h in xrange(H):
    for w in xrange(W):
      b = getbasin(h,w)
      if b not in L: L[b] = letters.pop(0)
      print L[b],
    print
T = int(sys.stdin.readline())
for i in xrange(T): domap(i)
