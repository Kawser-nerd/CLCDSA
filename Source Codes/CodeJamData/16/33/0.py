from sys import stdin

def getint():
    return int(stdin.readline())

def getints():
    return tuple(int(z) for z in stdin.readline().split())

def solve(j,p,s,k):
    if k >= p:
        return [(i1,i2,i3) for i1 in xrange(j) for i2 in xrange(p) for i3 in xrange(min(s,k))]
    return [(i1,i2,(i1+i2+i3)%p) for i1 in xrange(j) for i2 in xrange(p) for i3 in xrange(k)]

for cn in xrange(1,1 + getint()):
    (j,p,s,k) = getints()
    ans = solve(j,p,s,k)
    print "Case #{}: {}\n{}".format(cn, len(ans), "\n".join(" ".join(str(v + 1) for v in outfit) for outfit in ans))
