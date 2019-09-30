
m={0:"OFF",1:"ON"}

def f(n,k) :
    return m[ int( ( (k+1) % (2**n) )==0) ]

#for k in range(50) :
#    print f(4,k)

import sys

t = int(sys.stdin.readline())
for i in range(1,t+1) :
    a = map(int,sys.stdin.readline().split())
    assert len(a)==2
    (n,k) = a
    print "Case #%d: %s" % ( i, f(n,k) )
