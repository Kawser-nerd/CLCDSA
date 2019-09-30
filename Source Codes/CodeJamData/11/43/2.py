#!/usr/bin/env python

import sys


cache = {}
def is_prime(n):
    if n in cache:
        return cache[n]
    cache[n] = kk(n)
    return cache[n]

def kk(n):
    if n == 2:
        return True
    if n % 2 == 0: 
        return False
    x = 3
    while x * x <= n:
        if n % x == 0:
            return False
        x += 2
    return True


def primes(n):
    res = [2]
    i = 3
    while i*i <= n:
        if is_prime(i):
            res.append(i)
        i+=2
    return res
    

def foo(ifile):
    n = int(ifile.readline())
    if(n == 1):
        return 0
    res = 0
    for x in primes:
        if x*x > n:
            break
        t = x * x
        while t <= n:
            res += 1
            t *= x
    return res+1

primes = [2]
def create_primes():
    x = 3
    while x*x <= 10**12:
        if is_prime(x):
            primes.append(x)
        x += 2


def main(ifile, ofile):
    create_primes()
    n = int(ifile.readline())
    for i in range(n):
        ofile.write("Case #%s: %s\n" % (i+1, foo(ifile)))

main(sys.stdin, sys.stdout)

