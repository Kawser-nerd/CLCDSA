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

## Setup
from os.path import basename, splitext
# Task letter
TASK=splitext(basename(__file__))[0]
print("Task {}".format(TASK))

## Input templates
# Line as int
#int(infile.readline())
# Line as many ints
#(int(s) for s in infile.readline().split())

## Precalculation
print("Precalculation...")
from string import maketrans
src = """aozq
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv"""
dst = """yeqz
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up"""
table = maketrans(src, dst)
print("Precalculation done.")

## Calculation
print("Calculation...")
with open(TASK+".in") as infile:
    with open(TASK+".out",mode="wt") as outfile:
        cases = int(infile.readline())
        for ncase in range(cases):
            print("Case #{nc}".format(nc=ncase+1))
            # Perform all nessesary calculation
            text = infile.readline().strip()
            data = text.translate(table)
            outfile.write("Case #{nc}: {data}\n".format(nc=ncase+1,data=data))
print("Calculation done.")
