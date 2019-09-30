#!/usr/bin/python
import string

def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x % y)

po = "Possible"
br = "Broken"

def solve(n, d, g):
    if d == 0:
        if g == 100: return br
        return po
    else:
        if d>0 and g==0: return br
        if d<100 and g==100: return br
        t = 100 / gcd(d, 100)
        if n < t: return br
        return po

f = open("input.txt", "r")
lines = [x for x in f]
f.close()

t = string.atoi(lines[0])
for i in xrange(t):
    (n, d, g) = map(string.atoi, lines[i+1].split())
    if len(lines[i+1].split()[0]) > 3: n = 200
    ans = solve(n, d, g)
    print "Case #%d: %s" % (i + 1, ans)
