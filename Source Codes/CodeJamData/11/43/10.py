#!/usr/bin/python2
### Google Code Jam template
## Library
# @memoized
def memoized(func):
    mem = {}
    def wrapped(*args):
        if args not in mem:
            mem[args] = func(*args)
        return mem[args]
    return wrapped

## Setup
# Task letter
TASK="C"

## Input templates
# Line as int
#int(infile.readline())
# Line as many ints
#(int(s) for s in infile.readline().split())

## Precalculation
print("Precalculation...")
import math
def isprime(num, primes):
    s = math.sqrt(num)
    for p in primes:
        if p > s:
            return True
        if num % p == 0:
            return False
    return True
primes = []
for i in xrange(2,10**6+1):
    if isprime(i, primes):
        primes.append(i)
print("Precalculation done.")

## Calculation
print("Calculation...")
with open(TASK+".in") as infile:
    with open(TASK+".out",mode="wt") as outfile:
        cases = int(infile.readline())
        for ncase in range(cases):
            # Perform all nessesary calculation
            N = int(infile.readline())
            s = math.sqrt(N)
            ans = 0
            for p in primes:
                if p > s: break
                ans += int(math.log(N,p))-1
            if N > 1:
                ans += 1
            outfile.write("Case #{nc}: {data}\n".format(nc=ncase+1,data=ans))
print("Calculation done.")
