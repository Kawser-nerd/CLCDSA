#!/usr/bin/python
from decimal import *
base=Decimal(3)+Decimal(5).sqrt()

def solve(m):
   return base**m%1000
      
if __name__ == "__main__":
   import sys
   N = int(sys.stdin.readline())   
   for i in xrange(N):
      m = int(sys.stdin.readline())   
      print "Case #%d: %03d" %(i+1,solve(m))

