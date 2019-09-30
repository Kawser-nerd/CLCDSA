#!/usr/bin/env python2.5
# -*- coding: iso-8859-1 -*-

#
# Google CodeJam Entry
#
# Usage <scriptname>.py inputfile >outputfile
#
# Copyright 2008 AussieSteve
#

from __future__ import with_statement

from optparse import OptionParser
import sys
import re
#import math
from mpmath import *   # mpmath available from http://code.google.com/p/mpmath/
mp.dps = 100

from scipy.optimize import fmin_powell  # scipy available from http://www.scipy.org/
from numpy import array, arange # numpy available from http://www.scipy.org/

parser = OptionParser()
parser.add_option("-d", "--debug", action="store_true", dest="debug")

(options, args) = parser.parse_args()

def decorator(old_decorator):
    "Restore original name, doc & dict for decorated functions"
    def new_decorator(f):
        g = old_decorator(f)
        g.__name__ = f.__name__
        g.__doc__ = f.__doc__
        g.__dict__.update(f.__dict__)
        return g

    new_decorator.__name__ = old_decorator.__name__
    new_decorator.__doc__ = old_decorator.__doc__
    new_decorator.__dict__.update(old_decorator.__dict__)

    return new_decorator

def memoize(cache=None):
    """Decorator to memoize a function
    Can be used on multiple functions
    Warning: Does not reclaim memory"""

    if cache == None:
        cache = {}

    @decorator
    def m(f):
        def g(*args, **kwargs):
            key = ( f, tuple(args), frozenset(kwargs.items()) )
            if key not in cache:
                cache[key] = f(*args, **kwargs)
            return cache[key]

        return g

    return m

def guess_cruiser(ships):
    xtot = 0
    ytot = 0
    ztot = 0
    ptot = 0
    for (x, y, z, p) in ships:
        xtot += mpf(1.0) * x / p
        ytot += mpf(1.0) * y / p
        ztot += mpf(1.0) * z / p
        ptot += p
    cruiser = array([(1.0 * xtot / ptot), (1.0 * ytot / ptot), (1.0 * ztot / ptot)])
    return cruiser

def power_needed(cruiser):
    cx, cy, cz = cruiser
    power = 0.0
    for (x, y, z, p) in ships:
        needed = (abs(x - cx) + abs(y - cy) + abs(z - cz)) / p
        if needed > power:
            power = needed
    return power

# Input file is first argument if present, or stdin
if args:
    input_filename = args[0]

    file = open(input_filename, 'r')
else:
    file = sys.stdin

num_tests = int(file.readline())
if options.debug:
    print "num_tests", num_tests

for test in range(1, num_tests + 1):
    s = int(file.readline())
    ships = []
    for ship in range(s):
        x, y, z, p = map(int, file.readline().split())
        ships.append((x, y, z, p))

    cruiser = guess_cruiser(ships)

    #cmin = fmin(power_needed, cruiser, ftol=mpf(1e-50), xtol=mpf(1e-50), disp = 1)
    cmin = fmin_powell(power_needed, cruiser, xtol=1e-50, ftol=1e-50, maxiter=None, maxfun=None, disp=0)
    # print cmin

    result = power_needed(cmin)

    print "Case #%s: %0.6f" % (test, result)
