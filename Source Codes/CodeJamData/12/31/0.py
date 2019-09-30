from sys import stdin

def getInt():
    return int(stdin.readline())
def getInts():
    return [int(z) for z in stdin.readline().split()]

for cn in xrange(1,1+getInt()):
    A = getInt()
    deps = [[i-1 for i in getInts()[1:]] for k in xrange(A)]
    deg = [len(z) for z in deps]
    mx = [[0 for i in xrange(A)] for j in xrange(A)]
    for k in xrange(A):
        for l in deps[k]:
            mx[l][k] += 1
    q = [i for i in xrange(A) if deg[i] == 0]
    qlen = len(q)
    qat = 0
    ok = True
    while ok and (qat < qlen):
        qi = q[qat]
        ok = (len(deps[qi]) == len(set(deps[qi])))
        qat += 1
        for k in xrange(A):
            if mx[qi][k] == 1:
                deps[k] += deps[qi]
                deg[k] -= 1
                if deg[k] == 0:
                    q += [k]
                    qlen += 1
    print "Case #%d: %s" % (cn, "Yes" if (not ok) else "No")


    
