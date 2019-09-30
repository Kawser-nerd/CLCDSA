import sys,re
from pprint import pprint

#fi = open('D.in','r')
#fo = open('D.out','w')
#fi = open('D-small-attempt0.in','r')
#fo = open('D-small-attempt0.out','w')
fi = open('D-large.in','r')
fo = open('D-large.out','w')
t = int(fi.readline())
for _ in range(1,t+1):
    n = int(fi.readline())
    v = map(int,fi.readline().split())
    vv = zip(v,sorted(v))
    r = filter(lambda (x,y):x!=y, vv)
    fo.write('Case #%d: %.6f\n' % (_, len(r)))
fi.close()
fo.close()
