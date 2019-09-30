#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)

def cb(x):
    ret = 0
    while x:
        ret += 1
        x &= (x-1)
    return ret

def log(x):
    ret = 0
    while x != 1:
        ret += 1
        x /= 2
    return ret

def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        p,q = map(int, sys.stdin.readline().split("/"))
        g = gcd(p, q)
        p /= g
        q /= g
        if cb(q) == 1:
            ret = 1
            while p * 2 < q:
                ret += 1
                p *= 2
            print "Case #" + str(t) +": " + str(ret)
        else:
            print "Case #" + str(t) +": impossible"


if __name__ == '__main__':
    main()
