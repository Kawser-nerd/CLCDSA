#!/usr/bin/env python

from __future__ import division

import collections
import itertools
import sys
import operator
import functools

class gcj:
    IN = sys.stdin
    buf = ''
    cur_case = 0

    @classmethod
    def id(x):
        return x

    @classmethod
    def _read_line(cls):
        if cls.buf:
            res = cls.buf
            cls.buf = ''
        else:
            res = cls.IN.readline()
        if not res:
            raise EOFError()
        return res

    @classmethod
    def line(cls, conv=str):
        line = cls._read_line()
        return conv(line.rstrip('\r\n'))

    @classmethod
    def splitline(cls, conv=str):
        line = cls._read_line()
        return [conv(x) for x in line.split()]

    @classmethod
    def whitespace(cls):
        line = None
        while not line:
            line = cls._read_line().lstrip()
        cls.buf = line

    @classmethod
    def token(cls, conv=str):
        cls.whitespace()
        line = cls._read_line()
        spl = line.split(None, 1)
        res = spl[0]
        assert line.startswith(res)
        cls.buf = line[len(res):]
        return conv(res)

    @classmethod
    def tokens(cls, cnt, conv=str):
        return [cls.token(conv) for _ in xrange(cnt)]

    @classmethod
    def case(cls):
        cls.cur_case += 1
        return 'Case #{}:'.format(cls.cur_case)

def is_prime(n):
    if n <= 2:
        return n == 2
    d = 3
    while d*d <= n:
        if n % d == 0:
            return False
        d += 2
    return True

def solve(n, primes):
    res = 0
    if n > 1:
        res += 1
    for p in primes:
        x = p**2
        while x <= n:
            res += 1
            x *= p
    return res

def go():
    try:
        with open('primes.txt', 'r') as f:
            primes = eval(f.read())
    except:
        primes = [2] + [x for x in xrange(3, 10**6, 2) if is_prime(x)]
        with open('primes.txt', 'w') as f:
            f.write(repr(primes) + '\n')

    t = gcj.token(int)
    for _ in xrange(t):
        n = gcj.token(int)
        print gcj.case(), solve(n, primes)

go()
