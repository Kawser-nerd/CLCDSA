#!/usr/bin/env python

from __future__ import division

import sys
import itertools

def parse_pattern(pattern):
    res = []
    while pattern:
        if pattern[0] == '(':
            i = pattern.find(')')
            res.append(set(pattern[1:i]))
            pattern = pattern[i+1:]
        else:
            res.append(set(pattern[0]))
            pattern = pattern[1:]
    return res

def matches_pattern(pattern, word):
    for p, w in itertools.izip(pattern, word):
        if w not in p:
            return False
    return True

def solve(pattern, words):
    p = parse_pattern(pattern)
    res = 0
    for w in words:
        if matches_pattern(p, w):
            res += 1
    return res

def go():
    l, d, n = [int(x) for x in sys.stdin.readline().split()]
    words = []
    for i in xrange(d):
        word = sys.stdin.readline().strip()
        words.append(word)
    for i in xrange(n):
        pattern = sys.stdin.readline().strip()
        print 'Case #%d: %d' % (i+1, solve(pattern, words))

go()
