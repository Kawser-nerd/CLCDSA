#!/usr/bin/env python

from math import *

def permutations(l):
    if len(l) < 2:
        yield l
    else:
        for k in permutations(l[1:]):
            for n in range(len(l)):
                yield k[:n] + [l[0]] + k[n:]

def transform(text, perm):
    res = [ None ]*len(text)
    for blk in range(len(text)/len(perm)):
        for n in range(len(perm)):
            res[len(perm)*blk + n] = text[len(perm)*blk + perm[n]]
    return res

def cost(text):
    last = None
    res  = 0
    for c in text:
        if c <> last:
            last = c
            res += 1
    return res

def solve(k, s):
    perms = list(permutations(range(k)))
    res = 999999999
    for p in perms:
        res = min(res, cost(transform(s, p)))
    return res

if __name__ == '__main__':
    from sys import stdin
    def read_line():    return stdin.readline()
    def read_words():   return read_line().split()
    def read_ints():    return map(int, read_words())
    def read_floats():  return map(float, read_words())

    cases, = read_ints()
    for c in range(cases):
        k, = read_ints()
        s, = read_words()
        print 'Case #%d:'%(c+1), solve(k, s)
