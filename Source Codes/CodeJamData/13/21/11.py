#!/usr/bin/env python

def solve(me, others):
    if me <= 1:
        return len(others)
    others = sorted(others)
    best = len(others)
    remaining = len(others)
    added = 0
    for mote in others:
        while me <= mote:
            me += me - 1
            added += 1
        me += mote
        remaining -= 1
        best = min(best, remaining + added)
    return best

if __name__ == "__main__":
    ncases = int(raw_input())
    for ncase in xrange(1, ncases + 1):
        me, nothers = map(int, raw_input().split())
        others = map(int, raw_input().split())
        print "Case #%d: %d" % (ncase, solve(me, others))
