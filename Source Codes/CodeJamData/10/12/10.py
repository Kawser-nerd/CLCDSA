#!/usr/bin/python
import sys

mm = []
cd=ci=M=N=0
pixels=[]
def cost(last,ix,canins):
  if ix==N:
    return 0
  kk = last+256*canins
  if mm[ix][kk]>=0:
    return mm[ix][kk]


  if (abs(last-pixels[ix])<=M):
    best = cost(pixels[ix],ix+1,1)
  else:
    best = -1;  
  if canins and M>0:
    for i in range(256):
      dist = abs(i-last)
      ins = (dist+M-1)//M
      th = ins*ci + cost(i,ix,0)
      if (th>=0 and (best<0 or th<best)):
        best = th
  # Del
  th = cd + cost(last,ix+1,1)
  if (th>=0 and (best<0 or th<best)):
    best = th

  # Chg
  for i in range(256):
    dist = abs(i-last)
    if (dist<=M):
       th = abs(i-pixels[ix]) + cost(i,ix+1,1)
       if (th>=0 and (best<0 or th<best)):
         best = th

  #print "cost("+str(last)+","+str(ix)+","+str(canins)+") = "+str(best)
  mm[ix][kk] = best
  return best

inp = [l.strip() for l in sys.stdin if l.strip()!='']
T = int(inp[0])
l = 1
for t in range(T):
  ds = [int(x) for x in inp[l].split(" ") if x!='']
  cd = ds[0]
  ci = ds[1]
  M = ds[2]
  N = ds[3]
  l += 1
  pixels = [int(x) for x in inp[l].split(" ") if x!='']
  l += 1
 # print pixels
  mm = [[-1 for j in range(512)] for i in range(N+1)]
  best = 1<<100
  for i in range(256):
    best = min(best,cost(i,0,0))
#  print "==>"+str(best)
  print "Case #%d: %d" % (t+1, best)

#  print "B? "+str(B)
#  print "R? "+str(R)

#  print ""+str(N)+","+str(K)+" => "
#  for s in board:
#    print "["+s+"]"
#  v = map(int, line.strip().split(" "))

