#!/usr/bin/env python
#coding=utf-8

sample ="""2
5
Yeehaw
NSM
Dont Ask
B9
Googol
10
Yeehaw
Yeehaw
Googol
B9
Googol
NSM
B9
NSM
Dont Ask
Googol
5
Yeehaw
NSM
Dont Ask
B9
Googol
7
Googol
Dont Ask
NSM
NSM
Yeehaw
Yeehaw
Googol"""

#infile = iter(sample.split('\n'))
infile = open("A-large.in",'r')
outfile = open("A-large.out",'w')

N = int(infile.next().strip())
for n in xrange(N):
    S = int(infile.next().strip())
    engine = []
    for s in xrange(S):
        engine.append(infile.next().strip())
    Q = int(infile.next().strip())
    query = []
    for q in xrange(Q):
        query.append(engine.index(infile.next().strip()))
    mask = []
    switch = 0
    mask[:] = engine
    while len(query) > 0:
        i = query.pop(0)
        mask[i] = 0
        if not any(mask):
            query.insert(0,i)
            switch += 1
            mask[:] = engine
    print "Case #%d: %d"%(n+1,switch)
    outfile.write("Case #%d: %d\n"%(n+1,switch))

infile.close()
outfile.close()