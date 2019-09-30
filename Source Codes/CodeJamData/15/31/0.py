# find 1 x w+t in 1 x w+2t
def g(c,w):
    if c == w:
        return w
    if c <= 2 * w - 1:
        return w + 1
    return 1 + g(c - w, w)

def h(c,w):
    if c < w:
        return 0
    return 1 + h(c - w, w)

def f(r,c,w):
    return (r - 1) * h(c, w) + g(c, w)

from sys import stdin

for case in xrange(1,1+int(stdin.readline())):
    (r, c, w) = tuple(int(z) for z in stdin.readline().split())
    print "Case #%d: %d" % (case, f(r, c, w))
