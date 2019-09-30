#!/usr/bin/env python2.5
from collections import defaultdict
DEBUG = False

def getint(file): return int(file.readline().strip())
def getstr(file): return file.readline().strip()
def parse_time(st):
    assert len(st) == 5
    return int(st[0:2])*60 + int(st[3:5])

def gettimes(file):
    times = file.readline().strip().split()
    assert len(times) == 2
    return [parse_time(time) for time in times]

def get2ints(file):
    ints = file.readline().strip().split()
    assert len(ints) == 2
    return [int(i) for i in ints]

def run_file(file):
    if isinstance(file, basestring): file = open(file)
    ncases = getint(file)
    cases = []
    for case in xrange(ncases):
        T = getint(file)
        NA, NB = get2ints(file)
        events = defaultdict(list)
        for i in xrange(NA):
            depart, arrive = gettimes(file)
            events[depart].append('-a')
            events[arrive+T].append('+b')
        for i in xrange(NB):
            depart, arrive = gettimes(file)
            events[depart].append('-b')
            events[arrive+T].append('+a')
        
        ares, bres = run_case(events)
        print "Case #%d: %d %d" % (case+1, ares, bres)

def run_case(events):
    atrains = btrains = 0
    amin = bmin = 0
    times = events.keys()
    times.sort()
    for time in times:
        if DEBUG: print time, events[time],
        for event in events[time]:
            if event == '+a': atrains += 1
            if event == '+b': btrains += 1
        for event in events[time]:
            if event == '-a': atrains -= 1
            if event == '-b': btrains -= 1
        if DEBUG: print atrains, btrains
        if atrains < amin: amin = atrains
        if btrains < bmin: bmin = btrains
    return -amin, -bmin

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

