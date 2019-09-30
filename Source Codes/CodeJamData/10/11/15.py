#!/usr/bin/python
import sys

def find(col,b,brd):
  return findV(col,b,brd) or findH(col,b,brd) or findTL(col,b,brd) or findTR(col,b,brd)

def findH(col,K,brd):
  N = len(brd)
  C = len(brd[0])
  found = 0
  for r in range(N):
    run=0    
    for c in range(C):
      run = run+1 if brd[r][c]==col else 0
      if run>=K:
        return 1
  return 0
def findV(col,K,brd):
  N = len(brd)
  C = len(brd[0])
  found = 0
  for c in range(C):
    run=0    
    for r in range(N):
      run = run+1 if brd[r][c]==col else 0
      if run>=K:
        return 1
  return 0

def findTL(color,K,brd):
  N = len(brd)
  brd2 = [("."*i)+brd[i]+("."*(N-i)) for i in range(N)]
  return findV(color,K,brd2)

def findTR(color,K,brd):
  N = len(brd)
  brd2 = [ ("."*(N-i))+brd[i]+("."*i) for i in range(N)]
  return findV(color,K,brd2)

inp = [l.strip() for l in sys.stdin if l.strip()!='']
T = int(inp[0])
l = 1
for t in range(T):
  d = [int(x) for x in inp[l].split(" ") if x!='']
  N = d[0]
  K = d[1]
  l += 1
  board = ["."*(N-len(s))+s for s in [s.replace(".","") for s in inp[l:l+N]]]
  B = find('B',K,board);
  R = find('R',K,board);
  l += N
  res = ("Both" if R else "Blue") if B else ("Red" if R else "Neither")
  print "Case #%d: %s" % (t+1, res)
#  print "B? "+str(B)
#  print "R? "+str(R)

#  print ""+str(N)+","+str(K)+" => "
#  for s in board:
#    print "["+s+"]"
#  v = map(int, line.strip().split(" "))

