from sys import stdin

def getint():
    return int(stdin.readline())

def getints():
    return tuple(int(z) for z in stdin.readline().split())

for cn in xrange(1,1 + getint()):
    n = getint()
    ps = getints()
    m1 = max((ps[i],i) for i in xrange(n))[1]
    m2 = max((ps[i],i) for i in xrange(n) if i != m1)[1]
    plan = []
    for k in xrange(ps[m1]-ps[m2]):
        plan.append([m1])
    for j in xrange(n):
        if j != m1 and j != m2:
            for z in xrange(ps[j]):
                plan.append([j])
    for j in xrange(ps[m2]):
        plan.append([m1,m2])
    print "Case #{}: {}".format(cn, " ".join("".join(chr(65+i) for i in step) for step in plan))
