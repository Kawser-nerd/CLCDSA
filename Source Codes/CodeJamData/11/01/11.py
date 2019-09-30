import sys,re
from pprint import pprint

fi = open('A-large.in','r')
fo = open('A-large.out','w')
t = int(fi.readline())
for _ in range(1,t+1):
    inp = fi.readline().split()
    n = int(inp[0])
    btn = zip(inp[1::2],map(int,inp[2::2]))
    o = b = 1
    to = tb = 0
    for c,x in btn:
        if c == 'O':
            to,o = to+abs(x-o)+1,x
            to = max(to,tb+1)
        else:
            tb,b = tb+abs(x-b)+1,x
            tb = max(tb,to+1)
    fo.write('Case #%d: %d\n' % (_,max(to,tb)))
fi.close()
fo.close()
