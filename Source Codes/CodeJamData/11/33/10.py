import sys

t = int(sys.stdin.readline())

for tt in range(t):
    n,l,h = map(int, sys.stdin.readline().split())
    o = map(int, sys.stdin.readline().split())

    b = False
    for i in range(l,h+1):
        a = True
        for x in o:
            if x % i != 0 and i % x != 0:
                a = False
                break
        if a == True:
            print "Case #%d: %d" % (tt+1, i)
            b = True
            break
    if b == False:
        print "Case #%d: NO" % (tt+1)

