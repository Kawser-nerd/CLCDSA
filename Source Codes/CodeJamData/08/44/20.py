#!/usr/bin/env python

import sys

readline = lambda : sys.stdin.readline()

N = int(readline())

def perms(li):
    if len(li) <=1:
        yield li
    else:
        for p in perms(li[1:]):
            for i in range(len(li)+1):
                yield p[:i] + li[0:1] + p[i:]

def rle(s):
    l = 1
    for i in range(1, len(s)):
        if s[i] != s[i-1]:
            l+=1
    return l

def encode(s, k, perm):
    enc = []
    for i in range(len(s)/k):
        block = []
        for l in range(k):
            block.append(s[i*k + perm[l]])
        enc += block
    return enc

for n in range(N):
    k = int(readline())
    S = readline().strip()
    Y = len(S)
    block = list(range(k))
    for p in perms(block):
        Y = min(rle(encode(S, k, p)), Y)
    print "Case #%d: %d" % (n + 1, Y)
        
