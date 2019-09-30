#!/usr/bin/python
import sys
from numpy import *

s=sys.stdin.readline()

def bin(n,k):
  if (k < 0 or k > n): return 0
  t = 1;
  for x in range(k):
    t = t*(n-x)/(x+1)
  return t

def doit(n,c):
  a = zeros((n+1,n+1))
  den = 1.0/bin(n,c);
  for i in range(n):
    for j in range(i,n+1):
      k = j-i;
      a[i,j] = bin(n-i,k) * bin(i,c-k) * den;
  b = eye(n+1)-a;
  a = linalg.solve(dot(b,b),a)
  return a[0,n];
    

for i in range(1,int(s)+1):
  s=sys.stdin.readline()
  [n,c]=map(int,s.split())
  print 'Case #%d: %0.8f' % (i,doit(n,c))
