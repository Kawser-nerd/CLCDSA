#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
INPUT = "B-large.in"
#INPUT = "B-small-attempt0.in"

def debug(*args):
    return
    sys.stderr.write(str(args) + "\n")

def do_trial(s):
    count = 0
    last = "+"
    for c in reversed(s):
        if c != last:
            count += 1
        last = c
    return count
    

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    s = f.readline()[:-1]
    v = do_trial(s)
    print "Case #%d: %s" % (i+1, v)
