#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys
from itertools import permutations

M = 1000000007
def modperm(p):
    r = 1
    for i in range(1, p+1):
        r *= i
        r %= M
    return r


def debug(*args):
    print(*args, file=sys.stderr)

ALPHABET = 'abcdefghijklmnopqrstuvwxyz'

class SolveError(Exception):
    pass

def solve2(cars):
    result = 0
    for perm in permutations(cars):
        cc = ''
        for car in perm:
            cc += car
        trimmed = trim(cc)
        if len(set(trimmed)) == len(trimmed):
            result += 1
    return result

def trim(car):
    trimmed = ''
    last = None
    for c in car:
        if c != last:
            trimmed += c
            last = c
    return trimmed

def solve(cars):
    start = {}
    end = {}
    singular = {}
    mid = {}

    for c in ALPHABET:
        start[c] = 0
        end[c] = 0
        singular[c] = 0
        mid[c] = 0

    pairs = []
    for car in cars:
        trimmed = trim(car)
        if len(trimmed) != len(set(trimmed)):
            raise SolveError('Duplicate cars in set')
        elif len(trimmed) == 1:
            singular[trimmed] += 1
        else:
            for i, c in enumerate(trimmed):
                if i == 0:
                    start[c] += 1
                elif i == len(trimmed) - 1:
                    end[c] += 1
                else:
                    mid[c] += 1
            pairs.append(trimmed[0] + trimmed[-1])


    # Merge cars for cycle check
    for i in range(len(pairs)-1, -1, -1):
        p1 = pairs[i]
        for j in range(0, i):
            p2 = pairs[j]
            if p1[0] == p2[-1]:
                p3 = p2 + p1
                pairs[j] = p3
                del pairs[i]
                break
            elif p1[-1] == p2[0]:
                p3 = p1 + p2
                pairs[j] = p3
                del pairs[i]
                break

    for car in pairs:
        trimmed = trim(car)
        if len(set(trimmed)) != len(trimmed):
            raise SolveError('Cycle detected')
    

    result = 1
    groups = len(cars)
    for c in ALPHABET:
        if mid[c] > 1:
            raise SolveError('%s in middle of more than 1 car' % c)
        elif mid[c] == 1:
            if start[c] > 0 or end[c] > 0 or singular[c] > 0:
                raise SolveError('%s in middle and other cars' % c)
        elif start[c] > 1 or end[c] > 1:
            raise SolveError('%s in multiple starts or ends' % c)
        else:
            # Valid
            result *= modperm(singular[c])
            if singular[c] + start[c] + end[c] > 1:
                groups -= singular[c] + start[c] + end[c] - 1

        result %= M

    result *= modperm(groups)
    result %= M
    return result

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    N = int(fin.readline())
    cars = fin.readline().split()

    try:
        # if len(cars) > 8:
        #     result = "too long"
        # else:
        #     result = solve2(cars)
        result = solve(cars)
    except SolveError as e:
        debug("Case #%d:" % case, e)
        result = 0


    print("Case #%d: %s" % (case, result))