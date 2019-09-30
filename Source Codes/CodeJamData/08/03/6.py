#!/usr/bin/env python2.5
import math
DEBUG = False

def getint(file): return int(file.readline().strip())
def getstr(file): return file.readline().strip()

def getfloats(file):
    parts = file.readline().strip().split()
    return [float(p) for p in parts]

def run_file(file):
    if isinstance(file, basestring): file = open(file)
    ncases = getint(file)
    cases = []
    for case in xrange(ncases):
        f, R, t, r, g = getfloats(file)
        innerR = R-t-f
        string = r+f
        square = g-2*f
        if square < 0: square = 0
        prob = run_case(R, innerR, string, square)
        print "Case #%d: %6.6f" % (case+1, prob)

def open_length(d, string, square):
    complete = d // (2*string + square)
    complete_dist = square*complete
    leftover = d % (2*string + square)
    if leftover > string+square: leftover_dist = square
    elif leftover > string: leftover_dist = leftover-string
    else: leftover_dist = 0
    return complete_dist + leftover_dist

nsteps = 777777
def run_case(outerR, innerR, string, square):
    # repeating pattern of st SQ st
    if square <= 0 or innerR <= 0: return 1.0
    total = 0.0
    increment = innerR/nsteps
    for step in xrange(nsteps):
        xpos = increment/2 + step*increment
        xposmod = xpos % (2*string+square)
        lowbound = xposmod-increment/2
        highbound = xposmod+increment/2
        low = max(lowbound, string)
        high = min(highbound, string+square)
        if low >= high: continue
        w = high-low
        d = math.cos(math.asin(xpos/innerR)) * innerR
        area = open_length(d, string, square) * w
        if DEBUG: print xpos, area
        total += area
    return 1.0 - total*4 / (math.pi * outerR * outerR)

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

