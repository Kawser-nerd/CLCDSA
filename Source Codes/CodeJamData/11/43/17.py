import sys

from math import *

def lg(a) :
    sys.stderr.write(str(a)+"\n")

def sieve(n) :
    sqrtn = int(n**0.5)
    sieve = [True] * (n+1)
    sieve[0] = False
    sieve[1] = False
    for i in range(2, sqrtn+1):
	if sieve[i]:
	    m = n//i - i
	    sieve[i*i:n+1:i] = [False] * (m+1)
    sieve = [i for i in range(n+1) if sieve[i]]
    return sieve

import math

s = sieve(1000001)

t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    n = int(sys.stdin.readline())
    sqrtn = int(n**0.5)
    print "Case #%d:" % testNr ,
    if n==1 :
	print 0
	continue
#    print n
    # s = sieve(sqrtn+1)
    sum = 1
    for p in s :
	if p*p>n :
	    break
	q = p*p
	while q<=n :
	    sum+=1
	    q *= p
#	e = int(math.log(n)/math.log(p)-1) # FPP?
#	sum += e
    print sum
