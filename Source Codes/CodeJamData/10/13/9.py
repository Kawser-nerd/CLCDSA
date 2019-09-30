import sys

from math import *
from itertools import *
from collections import defaultdict

def lg(a) :
    sys.stderr.write(str(a)+"\n")

def GCD(x, y):
 if x < 0 : x = -x
 if y < 0 : y = -y
 if x + y > 0 :
  g = y
  while x > 0:
   g = x
   x = y % x
   y = g
  return g
 else:
  return 0

def loser(a,b) :
    tau = (sqrt(5)-1)/2
    if a>b :                                                                                
	a,b = b,a
    return float(a)/b>tau
		    

t = int(sys.stdin.readline())
tau = (sqrt(5)-1)/2
for testNr in range(1,t+1) :
    sol = 0
    (a1,a2,b1,b2) = map(int,sys.stdin.readline().split())
    for b in range(b1,b2+1) :
	around1 = int(ceil(b*tau))
	around2 = int(floor(b/tau))
	#print b,around1,around2
	if around1>a2 or around2<a1 :
	    got = a2-a1+1
	else :
	    if around1<a1 :
		around1=a1
	    if around2>a2 :
		around2=a2
	    got = (a2-a1+1)-(around2-around1+1)
	sol += got

    print "Case #%d:" % testNr ,
    print sol
    sys.stdout.flush()

