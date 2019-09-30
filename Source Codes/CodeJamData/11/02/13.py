import sys,re
from pprint import pprint

#fi = open('B.in','r')
#fo = open('B.out','w')
#fi = open('B-small-attempt0.in','r')
#fo = open('B-small-attempt0.out','w')
fi = open('B-large.in','r')
fo = open('B-large.out','w')
t = int(fi.readline())
for _ in range(1,t+1):
    inp = fi.readline().split()
    C = int(inp[0])
    cb = inp[1:C+1]
    inp = inp[C+1:]
    D = int(inp[0])
    op = inp[1:D+1]
    inp = inp[D+1:]
    n = int(inp[0])
    inp = inp[1]
    base = 'QWERASDF'

    trs = dict()
    for x in cb:
        if not (set(x[:2]) <= set(base) and x[2] not in base):
            raise ValueError
        trs[x[:2]] = x[2]
        trs[x[1]+x[0]] = x[2]
    ops = dict()
    for x in op:
        if not (set(x) <= set(base)):
            raise ValueError
        if x[0] in ops:
            ops[x[0]] |= set(x[1])
        else:
            ops[x[0]] = set(x[1])
        if x[1] in ops:
            ops[x[1]] |= set(x[0])
        else:
            ops[x[1]] = set(x[0])
    r = list()
    for c in inp:
        if len(r)>0 and r[-1]+c in trs:
            r[-1] = trs[r[-1]+c]
        elif (c in ops) and (not set(r).isdisjoint(ops[c])):
            r = list()
        else:
            r.append(c)
    sr = '['+', '.join(r)+']'
    fo.write('Case #%d: %s\n' % (_, sr))
fi.close()
fo.close()
