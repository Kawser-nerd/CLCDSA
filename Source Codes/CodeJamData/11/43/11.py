#!/usr/bin/env python

import sys
from numpy import *


primes = [2]
def isprime(n):
    m = int(sqrt(n)+.5)
    for k in primes:
        if n%k==0:
            return False
        if k>m:
            return True
    return True
for i in range(3,int(1e6),2):
    if isprime(i):
        primes.append(i)
# print primes
# print len(primes)

def maxpow(n, p):
    ret = 0
    while n>=p:
        n //= p
        ret += 1
    return ret

def solve():
    N = int(sys.stdin.readline())
    if N==1:
        return 0
    pp = [maxpow(N,p) for p in primes]
    high = sum(pp)+1
    low = sum(map(bool,pp))
    # print low, high, high-low
    return high-low



if __name__=="__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        print "Case #{}: {}".format(t+1, solve())

    
    
