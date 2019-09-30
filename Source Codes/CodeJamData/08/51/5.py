#!/usr/bin/env python

import sys

DIR_TO_V={
    "N":0,
    "E":1,
    "S":2,
    "W":3
}

V_TO_DIR="NESW"

def turn(which, dir):
    v = DIR_TO_V[dir]
    v += which
    v %=4
    return V_TO_DIR[v]

def delta_for_dir(dir):
    return { "N" : (0,1), "S" : (0,-1), "E" : (1,0), "W" : (-1,0)}[dir]

def do_trial(f):
    L = int(f.readline())
    st_pairs = []
    while len(st_pairs) < L*2:
        st_pairs = st_pairs + [x for x in f.readline().split()]

    ud_segs = dict()
    lr_segs = dict()
    dir = 'N'
    x,y=0,0
    min_x,min_y,max_x,max_y=0,0,0,0

    #print st_pairs

    while len(st_pairs)>0:
        s,t = st_pairs[0:2]
        st_pairs = st_pairs[2:]
        t = int(t)
        while t>0:
            t = t-1
            for d in s:
                if d == 'L':
                    dir = turn(-1, dir)
                if d == 'R':
                    dir = turn(1,dir)
                if d == 'F':
                    delta = delta_for_dir(dir)
                    if delta[1] == 0:
                        st = ud_segs.setdefault(x+delta[0]/2.0,set())
                        #print st
                        st.add(y)
                    else:
                        st = lr_segs.setdefault(y+delta[1]/2.0,set())
                        #print st
                        st.add(x)
                    x,y = x+delta[0],y+delta[1]
                    #print x,y
                    min_x = min(x,min_x)
                    max_x = max(x,max_x)
                    min_y = min(y,min_y)
                    max_y = max(y,max_y)

    if (x,y) != (0,0):
        print x,y
        assert (x,y) == (0,0)

    #print ud_segs
    #print lr_segs

    #print min_x, max_x, min_y, max_y
    area = 0

    stdout = file("/dev/null", "w")

    outside=[]

    for y in range(min_y-1, max_y+2):
        stdout.write(" ")
        for x in range(min_x-1, max_x+2):
            if y in ud_segs.get(x+0.5, []):
                stdout.write(" _")
            else:
                stdout.write("  ")
        #print
        for x in range(min_x-1, max_x+2):
            if x in lr_segs.get(y+0.5,[]):
                n = "|"
            else:
                n = " "
            is_pocket = False
            # count above, below
            l_count = 0
            s_count = 0
            for y0 in ud_segs.get(x-0.5,[]):
                if y0<=y: l_count = l_count+1
                else: s_count = s_count+1
            #print "count", x,y,l_count,s_count
            if l_count%2 == 0 and s_count%2 == 0 and s_count>0 and l_count>0:
                outside.append((x,y))
                #print "***", x, y
                area = area + 1
                stdout.write("*" + n)
                continue
            # count left, right
            l_count = 0
            s_count = 0
            for x0 in lr_segs.get(y+0.5, []):
                if x0<x: l_count = l_count+1
                else: s_count = s_count+1
            #print "count", x,y,l_count,s_count
            if l_count%2 == 0 and s_count%2 == 0 and s_count>0 and l_count>0:
                #print "***", x, y
                outside.append((x,y))
                area = area + 1
                stdout.write("*" + n)
                continue
            stdout.write(" " + n)
        #print

    #print ud_segs, lr_segs
    #print "OUTSIDE", outside
    return area

f = sys.stdin
#f = file("tiny.in")
count = int(f.readline())
for i in range(count):
    r = do_trial(f)
    print "Case #%d: %s" % (i+1, r)
