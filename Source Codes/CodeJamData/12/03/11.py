#! /usr/bin/env python
# -*- coding: utf-8 -*-

def gen(a):
    tmp = a
    mul = 1
    while True:
        tmp /= 10
        if tmp == 0:
            break
        mul *= 10

    aa = a
    while True:
        last = a % 10
        a /= 10
        a += last * mul

        if aa == a:
            break

        yield a

def main():
    t = getLineAs(int)[0]

    for i in range(1, t + 1):
        (a, b) = getLineAs(int)
        ans    = 0

        for n in range(a, b + 1):
            for m in gen(n):
                if m > n and m <= b:
                    ans += 1

        print "Case #%d: %d" % (i, ans)

    return 0


## -------------------------------------------
## TEMPLATE

from sys import stdin
from sys import setrecursionlimit
from copy import deepcopy
from math import sqrt
from itertools import permutations
from itertools import combinations

def getline():
	return stdin.readline()

def getLineAs(tp):
	return map(tp, getline().split())

def array(n, init = 0):
	return [deepcopy(init) for i in range(n)]

if __name__ == "__main__":
	setrecursionlimit(1024 * 1024)
	main()
