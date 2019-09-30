#!/usr/bin/env python
#coding=utf-8

import time

sample = """1
1
2 2
12:04 12:05
12:07 12:10
12:03 12:06
12:10 12:11"""

#infile = iter(sample.split('\n'))
infile = open('B-large.in','r')
outfile = open('B-large.out','w')

def m(tt):
    return reduce(lambda x,y: x*60+y, map(lambda x: int(x), tt.split(':')))

def scmp(x,y):
    if x[0] < y[0]:
        return -1
    elif x[0] > y[0]:
        return 1
    else:
        if x[1] == 'da' or x[1] == 'db':
            return 1
        else:
            return -1
        

N = int(infile.next().strip())
for n in xrange(N):
    axis = []
    t = int(infile.next().strip())
    nn = infile.next().strip().split()
    NA, NB = [int(x) for x in nn]
    for na in xrange(NA):
        trip = infile.next().strip().split()
        axis.append((m(trip[0]),'da'))
        axis.append((m(trip[1]),'ab'))
    for nb in xrange(NB):
        trip = infile.next().strip().split()
        axis.append((m(trip[0]),'db'))
        axis.append((m(trip[1]),'aa'))
    axis.sort(cmp=scmp)
    docka = []
    dockb = []
    starta = 0
    startb = 0
    for e in axis:
        if e[1] == 'da':
            if len(docka) == 0:
                starta += 1
            elif docka[0]+t > e[0]:
                starta += 1
            else:
                docka.pop(0)
        elif e[1] == 'db':
            if len(dockb) == 0:
                startb += 1
            elif dockb[0]+t > e[0]:
                startb += 1
            else:
                dockb.pop(0)
        elif e[1] == 'aa':
            docka.append(e[0])
        elif e[1] == 'ab':
            dockb.append(e[0])
    print "Case #%d: %d %d"%(n+1, starta, startb)
    outfile.write("Case #%d: %d %d\n"%(n+1, starta, startb))

infile.close()
outfile.close()    
