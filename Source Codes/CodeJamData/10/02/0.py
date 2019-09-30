import sys, os

c = int(sys.stdin.readline())

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

for i in xrange(c):
    times = map(int, sys.stdin.readline().split())[1:]
    times.sort()
    g = times[1] - times[0]
    for j in xrange(1, len(times)):
        g = gcd(g, times[j] - times[j-1])
    next = ((times[0] + g - 1) / g) * g
    print "Case #%d: %d" % (i+1, next - times[0])
