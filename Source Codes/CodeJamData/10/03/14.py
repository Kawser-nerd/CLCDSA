#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by Graham Dennis on 2010-05-08.
Copyright (c) 2010 __MyCompanyName__. All rights reserved.
"""

import sys

def main(argv=None):
    if argv is None:
        argv = sys.argv
    f = file(sys.argv[1])
    
    T = int(f.readline())
    for t in xrange(T):
        R, k, N = map(int, f.readline().split())
        groups = map(int, f.readline().split())
        
        next = [None] * N
        earnt = [None] * N
        
        def lengthEarningsFromTo(start, end):
            group = start
            earnings = 0
            length = 0
            while True:
                earnings += earnt[group]
                group = next[group]
                length += 1
                if group == end:
                    return length, earnings
        
        group = 0
        while True:
            if earnt[group]: break
            lastGroup = group
            placesUsed = 0
            while placesUsed + groups[group] <= k:
                placesUsed += groups[group]
                group = (group + 1) % N
                if group == lastGroup: break
            next[lastGroup] = group
            earnt[lastGroup] = placesUsed
        
        startupLength, startupEarnings = lengthEarningsFromTo(0, lastGroup) if lastGroup != 0 else (0, 0)
        cycleLength, cycleEarnings = lengthEarningsFromTo(lastGroup, lastGroup)
        
        earnings = 0
        if R - startupLength > 0:
            R -= startupLength
            earnings += startupEarnings
            earnings += (R // cycleLength) * cycleEarnings
            R = R % cycleLength
            group = lastGroup
        else:
            group = 0
        
        while R:
            earnings += earnt[group]
            group = next[group]
            R -= 1
        
        print 'Case #%i: %s' % (t+1, earnings)
        
    


if __name__ == "__main__":
    sys.exit(main())
