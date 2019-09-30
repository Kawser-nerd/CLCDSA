#!/usr/bin/python
   
if __name__ == "__main__":
   import sys
   sys.setrecursionlimit(1000000)
   N = int(sys.stdin.readline())   
   for i in xrange(N):
      M = int(sys.stdin.readline())   
      v1=map(int,sys.stdin.readline().split())
      v2=map(int,sys.stdin.readline().split())
      v1.sort()
      v2.sort(reverse=True)
      s=0
      for j in xrange(M):
         s+=v1[j]*v2[j]
      print "Case #%d: %d" %(i+1,s)

