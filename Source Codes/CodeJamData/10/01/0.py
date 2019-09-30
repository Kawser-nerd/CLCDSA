import sys, os

t = int(sys.stdin.readline())

for i in xrange(t):
    s = sys.stdin.readline().split()
    n, k = map(int, s)
    print "Case #%d:" % (i+1),
    for j in xrange(n):
        if k & (2**j) == 0:
            print "OFF"
            break
    else:
        print "ON"
