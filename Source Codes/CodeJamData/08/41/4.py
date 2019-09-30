#!/usr/bin/env python2.5
import math, sys, os, re, psyco
psyco.profile()

DEBUG = False
def getline(file, types):
    parts = file.readline().strip().split()
    got = []
    for i in xrange(len(parts)):
        got.append(types[i](parts[i]))
    return got

def getints(file):
    parts = file.readline().strip().split()
    return [int(x) for x in parts]

def getint(file):
    ints = getints(file)
    assert len(ints) == 1
    return ints[0]

def run_file(file, out=None):
    if out is None and isinstance(file, basestring) and file.endswith('.in'):
        out = file[:-3]+'.out'
    if out is None: outfile = sys.stdout
    else: outfile = open(out, 'w')
    if isinstance(file, basestring): file = open(file)


    ncases = getint(file)
    for case in xrange(ncases):
        M, V = getints(file)
        nodes = []
        for m in xrange((M-1)/2):
            G, C = getints(file)
            nodes.append([True, bool(G), bool(C), False, 1000000])
        for m in xrange((M+1)/2):
            v = getint(file)
            nodes.append([False, False, False, bool(v), 1000000])
        answer = run_case(M, V, nodes)
        print >> outfile, "Case #%d: %s" % (case+1, answer)

IS_NODE, IS_AND, CHANGEABLE, VALUE, TOCHANGE = range(5)

def update(nodes):
    D = (len(nodes)-1)/2
    for i in reversed(range(D)):
        tochange_and = 0
        tochange_or = 0
        and_value = nodes[i*2+1][VALUE] and nodes[i*2+2][VALUE]
        if and_value:
            tochange_and = min(nodes[i*2+1][TOCHANGE],
            nodes[i*2+2][TOCHANGE])
        else:
            tochange_and = 0
            if not nodes[i*2+1][VALUE]:
                tochange_and += nodes[i*2+1][TOCHANGE]
            if not nodes[i*2+2][VALUE]:
                tochange_and += nodes[i*2+2][TOCHANGE]
            
        or_value = nodes[i*2+1][VALUE] or nodes[i*2+2][VALUE]
        if not or_value:
            tochange_or = min(nodes[i*2+1][TOCHANGE],
            nodes[i*2+2][TOCHANGE])
        else:
            tochange_or = 0
            if nodes[i*2+1][VALUE]:
                tochange_or += nodes[i*2+1][TOCHANGE]
            if nodes[i*2+2][VALUE]:
                tochange_or += nodes[i*2+2][TOCHANGE]
        if nodes[i][IS_AND]:
            nodes[i][VALUE] = and_value
            if nodes[i][CHANGEABLE]:
                if and_value != or_value: nodes[i][TOCHANGE] = 1
                else: nodes[i][TOCHANGE] = min(tochange_and, tochange_or+1)
            else:
                nodes[i][TOCHANGE] = tochange_and
        else:
            nodes[i][VALUE] = or_value
            if nodes[i][CHANGEABLE]:
                if and_value != or_value: nodes[i][TOCHANGE] = 1
                else: nodes[i][TOCHANGE] = min(tochange_or, tochange_and+1)
            else:
                nodes[i][TOCHANGE] = tochange_or
            
def run_case(M, V, nodes):
    update(nodes)
    if nodes[0][VALUE] == V: return 0
    elif nodes[0][TOCHANGE] >= 1000000: return "IMPOSSIBLE"
    else: return nodes[0][TOCHANGE]

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

