#!/usr/bin/env python

import sys

def b():
    t = int(sys.stdin.readline())
    for ix,line in enumerate(sys.stdin):
        row = line.strip().split()
        c = int(row[0])
        mapstrs = row[1:1+c]
        d = int(row[1+c])
        oppstrs = row[2+c: 2+c+d]
        start = row[3+c+d]
        maps = {}
        for m in mapstrs:
            maps[m[:2]] = m[2]
            maps[m[1] + m[0]] = m[2]
        opps = {}
        for o in oppstrs:
            opps.setdefault(o[0], []).append(o[1])
            opps.setdefault(o[1], []).append(o[0])      
        stack = []
        for s in start:
            stack.append(s)
            if len(stack) > 1:
                key = "".join(stack[-2:])
                if key in maps:
                    stack[-2:] = maps[key]
                else:
                    clear = False
                    for ele in stack[:-1]:
                        if ele in opps.get(s,[]):
                            clear = True
                            break
                    if clear:
                        stack = []
        print "Case #%d: [%s]" % (ix + 1, ", ".join(stack))
            

b()
