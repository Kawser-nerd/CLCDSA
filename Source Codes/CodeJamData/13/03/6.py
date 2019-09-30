SP = []

def rev(n):
    m = 0
    while n>0:
        m=10*m+n%10
        n/=10
    return m

def numize(seq):
    n = 0
    for i in seq:
        n=n*10+i
    return n

pal = []
q = [(1, 1), (4, 2), (9, 3)]
for i in range(1, 53):
    nq = []
    for (l, n) in q:
        for k in [0,1,2]:
            if l + k*k <=4:
                num = n*10+k
                nq.append((l+k*k, num))
                pal.append(num*10**(i+1)+rev(num))
                pal.append(num*10**(i+2)+rev(num))
                pal.append(num*10**(i+2)+rev(num)+10**(i+1))
                if l+k*k<=2:
                    pal.append(num*10**(i+2)+rev(num)+2*10**(i+1))
    q = nq
    #print pal
pal+=[1,2,3,11,22,101,111,121,202,212]

pal = sorted(pal)
#print pal[:40]
pal = [x*x for x in pal]


n = int(raw_input())
from bisect import *
for v in range(n):
    a,b = [int(x) for x in raw_input().split(' ')]
    i = bisect_left(pal, a)
    j = bisect_right(pal, b)
    print "Case #%d: %d"%(v+1,j-i)
