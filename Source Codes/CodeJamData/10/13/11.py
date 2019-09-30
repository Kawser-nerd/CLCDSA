#!/usr/bin/python
import sys

def win(a,b):
  l=win2(a,b)
  r=win2(b,a)
  if (l==1 or r==1):
    return 1
  else:
    return 0

def win2(a,b):
  # a = a-kb  
  if a<b:
    return 0
  c = min(a-b, a-((a-b)//b-1)*b)
  while (c>0):
    if (win(c,b)==0):
      return 1
    c -= b
  return 0

inp = [l.strip() for l in sys.stdin if l.strip()!='']
T = int(inp[0])
l = 1
for t in range(T):
  ds = [int(x) for x in inp[l].split(" ") if x!='']
  a1 = ds[0]
  a2 = ds[1]
  b1 = ds[2]
  b2 = ds[3]
  l += 1
  k = 0
  for a in range(a1,a2+1):
    for b in range(b1,b2+1):
      k += win(a,b)
  print "Case #%d: %d" % (t+1, k)

#  print "B? "+str(B)
#  print "R? "+str(R)

#  print ""+str(N)+","+str(K)+" => "
#  for s in board:
#    print "["+s+"]"
#  v = map(int, line.strip().split(" "))

