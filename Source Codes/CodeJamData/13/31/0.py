#! /usr/bin/env python

from sys import stdin

ntest = input()
vowels = {'a', 'e', 'i', 'o', 'u'}

for test in xrange(ntest):
    s, n = stdin.readline().strip().split(' ')
    n = int(n)
    count = 0 # how many consecutive consonants
    pos = -1 # position of the last substring of n consonants
    nvalue = 0
    for i, c in enumerate(s):
        if c in vowels:
            count = 0
        else:
            count += 1
        if count >= n:
            pos = i + 2 - n
        if pos >= 0:
            nvalue += pos
    print "Case #{}: {}".format(test+1, nvalue)
