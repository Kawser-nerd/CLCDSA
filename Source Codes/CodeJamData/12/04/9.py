#!/usr/bin/python2
### Google Code Jam template
# Futures
from __future__ import division
from __future__ import with_statement
from __future__ import print_function
## Library
# @memoized
def memoized(func):
    mem = {}
    def wrapped(*args):
        if args not in mem:
            mem[args] = func(*args)
        return mem[args]
    return wrapped

## Input templates
# Line as int
readint = lambda infile: int(infile.readline())
# Line as many ints
readints = lambda infile: (int(s) for s in infile.readline().split())

# Precalculation of shared data
class SharedData():
    def __init__(self):
        ## User code here
        pass

# Main processing function
def process(infile, ncase, shared):
    ## User code here
    H, W, D = readints(infile)
    level = [infile.readline().strip() for i in xrange(H)]
    for lnum, line in enumerate(level):
        for pos, char in enumerate(line):
            if char == 'X':
                break
        else:
            continue
        break
    pos = (lnum, pos)
    level = [l.replace('X', '.') for l in level]
    reflections = 0
    for i in xrange(-D, D + 1):
        for j in xrange(-D, D + 1):
            if (i ** 2 + j ** 2 <= D ** 2 and
                    (i != 0 or j != 0) and
                    gcd(abs(i), abs(j)) == 1):
                if trace(level, pos, (i, j), D):
                    reflections += 1
    return reflections

from math import sqrt
def trace(level, pos, vec, dist):
    factor = lcm(abs(vec[0]), abs(vec[1])) * 2
    max_substeps = int(factor * dist / sqrt(vec[0] ** 2 + vec[1] ** 2))
    orig = (pos[0] * factor + (factor // 2), pos[1] * factor + (factor // 2))
    cur = orig
    substeps = 0
    while True:
        subs = min(left(cur[0], vec[0], factor), left(cur[1], vec[1], factor))
        substeps += subs
        if substeps > max_substeps:
            return False
        cur = (cur[0] + vec[0] * subs, cur[1] + vec[1] * subs)
        if cur == orig:
            return True
        # Mirrors
        sV = vec[0] < 0
        V = not (cur[0] % factor)
        pV = cur[0] // factor
        sH = vec[1] < 0
        H = not (cur[1] % factor)
        pH = cur[1] // factor
        part = (level[pV - 1][pH - 1:pH + 1],
                level[pV][pH - 1:pH + 1])
        if sH and H:
            part = tuple(p[::-1] for p in part)
        if sV and V:
            part = part[::-1]
        if H and V:
            if part == (".#", "##"):
                vec = [-vec[0], -vec[1]]
            elif part == (".#", ".#"):
                vec = [vec[0], -vec[1]]
            elif part == ("..", "##"):
                vec = [-vec[0], vec[1]]
            elif part == ("..", ".#"):
                return False
        elif H:
            if part[1][1] == "#":
                vec = [vec[0], -vec[1]]
        elif V:
            if part[1][1] == "#":
                vec = [-vec[0], vec[1]]

def left(pos, vel, factor):
    factor //= 2
    if vel == 0:
        return 10**9 # Infinite
    frac_pos = pos % factor
    if vel > 0:
        frac_pos = factor - frac_pos
    if frac_pos == 0:
        frac_pos = factor
    return frac_pos // abs(vel)
    

def lcm(a, b):
    if a == 0:
        return b
    if b == 0:
        return a
    return a * b // gcd(a, b)

def gcd(a, b):
    if a == b:
        return a
    if a < b:
        return gcd(b, a)
    if b == 0: return a
    return gcd(b, a%b)

# Script code
if __name__ == '__main__':
    ## Setup
    # Task letter
    from os.path import basename, splitext
    TASK=splitext(basename(__file__))[0]
    print("Task {}".format(TASK))
    from sys import argv
    if len(argv) > 1:
        print("Filename given: {}".format(argv[1]))
        FILE = argv[1][:-3]
    else:
        FILE = TASK
    ## Precalculation
    print("Precalculation...")
    shared = SharedData()
    print("Precalculation done.")
    
    ## Calculation
    print("Calculation...")
    with open(FILE + ".in") as infile:
        with open(FILE + ".out",mode="wt") as outfile:
            cases = int(infile.readline())
            for ncase in range(cases):
                print("Case #{nc}".format(nc=ncase + 1))
                # Perform all nessesary calculation
                data = process(infile, ncase=ncase, shared=shared)
                outfile.write("Case #{nc}: {data}\n".format(
                        nc=ncase + 1,data=data))
    print("Calculation done.")
