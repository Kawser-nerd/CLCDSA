import sys
from numpy import *
import heapq

def ReadInt():
  return int(sys.stdin.readline())

def ReadInts():
  return map(int,sys.stdin.readline().split())

C = ReadInt()

def printTimes(times):
  print times[:,:,0]
  print times[:,:,1]
  print times[:,:,2]
  print times[:,:,3]

for case in xrange(1,C+1):
  N,M = ReadInts()
  S = zeros((N,M),'i8')
  W = zeros((N,M),'i8')
  T = zeros((N,M),'i8')
  for n in xrange(N):
    row = ReadInts()
    for m in xrange(M):
      S[n,m]=row[3*m]
      W[n,m]=row[3*m+1]
      T[n,m]=row[3*m+2]
  times = ones((N,M,4),'i8')*(10**14)
  heap = []
  start = (0,(N-1,0,0))
  times[start[1]]=start[0]
  heapq.heappush(heap,start)
  CycleT = S+W
#  print "++++++"
#  print S
#  print CycleT
#  print T
  while(heap[0][0]<times[0,M-1,3]):
    item = heapq.heappop(heap)
    loc = item[1]
    n,m,p = loc
    time = item[0]
    if times[loc]<time:
      continue
    off = (time - T[n,m])%CycleT[n,m]
    steps = []
    if p==0:
      steps.append((time+2,(n+1,m,1)))
      steps.append((time+2,(n,m-1,2)))
      if off<S[n,m]:
        steps.append((time+1,(n,m,1)))
        steps.append((time+1+S[n,m]-off,(n,m,2)))
      else:
        steps.append((time+1+CycleT[n,m]-off,(n,m,1)))
        steps.append((time+1,(n,m,2)))
    elif p==1:
      steps.append((time+2,(n-1,m,0)))
      steps.append((time+2,(n,m-1,3)))
      if off<S[n,m]:
        steps.append((time+1,(n,m,0)))
        steps.append((time+1+S[n,m]-off,(n,m,3)))
      else:
        steps.append((time+1+CycleT[n,m]-off,(n,m,0)))
        steps.append((time+1,(n,m,3)))
    elif p==2:
      steps.append((time+2,(n+1,m,3)))
      steps.append((time+2,(n,m+1,0)))
      if off<S[n,m]:
        steps.append((time+1,(n,m,3)))
        steps.append((time+1+S[n,m]-off,(n,m,0)))
      else:
        steps.append((time+1+CycleT[n,m]-off,(n,m,3)))
        steps.append((time+1,(n,m,0)))
    elif p==3:
      steps.append((time+2,(n-1,m,2)))
      steps.append((time+2,(n,m+1,1)))
      if off<S[n,m]:
        steps.append((time+1,(n,m,2)))
        steps.append((time+1+S[n,m]-off,(n,m,1)))
      else:
        steps.append((time+1+CycleT[n,m]-off,(n,m,2)))
        steps.append((time+1,(n,m,1)))
    
    for ti,(ni,mi,pi) in steps:
      if ni<0 or mi<0 or ni>=N or mi>=M:
        continue
      if ti < times[ni,mi,pi]:
        times[ni,mi,pi]=ti
        heapq.heappush(heap,(ti,(ni,mi,pi)))
    
#    if case ==4:
#      print "--",item
#      printTimes(times)
      
    
  print "Case #%s: %s"%(case,times[0,M-1,3])