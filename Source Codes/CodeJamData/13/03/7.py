from Queue import Queue
import bisect
import sys

def rev(x):
    y=0
    while x!=0:
        y=y*10+x%10
        x/=10
    return y

def zfair(x):
    while x!=0 and x%10==0:
        x/=10
    return x==rev(x)
    

qu = Queue()
qu.put("")
qu.put("0")
qu.put("1")
qu.put("2")

v=[1,4,9]
while not qu.empty():
    p=qu.get()
    for a in range(0,3):
        g = str(a) + p + str(a)
        # if len(g)>10: break # for small
        if len(g)>52: break 
        x = int(g)
        if zfair(x*x):
            qu.put(g)
            if a>0:
                v.append(x*x)

v.sort()

t=int(sys.stdin.readline())
for tc in range(1, t+1):
    s=sys.stdin.readline().split()
    a=map(lambda x: int(x), s)
    print "Case #%d: %s" % (tc, bisect.bisect_right(v, a[1])-bisect.bisect_left(v, a[0]))

