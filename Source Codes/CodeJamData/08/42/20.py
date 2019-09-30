#!/usr/bin/python

def find(N,M,A):
   for x1 in xrange(N+1):
      for y1 in xrange(M+1):
         for x2 in xrange(x1+1):
            for y2 in xrange(y1,M+1):
               if x1*y2-y1*x2==A:
                  return "%d %d %d %d %d %d" %(0,0,x1,y1,x2,y2)
   return "IMPOSSIBLE"
   
if __name__ == "__main__":
   import sys
   sys.setrecursionlimit(1000000)
   C = int(sys.stdin.readline())   
   for i in xrange(C):
      N,M,A=map(int,sys.stdin.readline().split())
      print "Case #%d: %s" %(i+1,find(N,M,A))
