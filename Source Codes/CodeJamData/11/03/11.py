import sys,re
from pprint import pprint

#fi = open('C-small-attempt0.in','r')
#fo = open('C-small-attempt0.out','w')
fi = open('C-large.in','r')
fo = open('C-large.out','w')
t = int(fi.readline())
for _ in range(1,t+1):
    n = int(fi.readline())
    v = map(int,fi.readline().split())
    s = 0
    ss = 0
    for x in v:
        s ^= x
        ss += x
    if s>0:
        fo.write('Case #%d: NO\n' % _)
    else:
        fo.write('Case #%d: %d\n' % (_, ss - min(v)))
fi.close()
fo.close()
