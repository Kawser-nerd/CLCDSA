f = open('B.txt')
C = int(f.readline())

def sat(ns, ms, N, M):
    good = True
    i = 0
    while good and i < M:
        goodC = False
        for ff in ms[i][0].keys():
            if ns[ff-1] == 0:
                goodC = True
                break
        if not goodC:
            for ff in ms[i][1].keys():
                if ns[ff-1] == 1:
                    goodC = True
                    break
        if not goodC:
            good = False
        i += 1
    return good

def impossible (ns, ms, N, M, mB):
    mBs = [x for x in ms if len(x[0].keys() + x[1].keys()) <= mB]
    bad = False
    i = 0
    while not bad and i < len(mBs):
        goodC = False
        for ff in mBs[i][0].keys():
            if ns[ff-1] == 0:
                goodC = True
                break
        if not goodC:
            for ff in mBs[i][1].keys():
                if ns[ff-1] == 1:
                    goodC = True
                    break
        if not goodC:
            bad = True
        i += 1
    return bad

def fix(ns, ms, N, M, mB):
    mBs = [x for x in ms if len(x[0].keys() + x[1].keys()) == mB]
    for m in mBs:
        if len(m[1]):
            ns[m[1].keys()[0] - 1] = 1
    return

for case in range(C):
    N = int(f.readline())
    M = int(f.readline())
    ns = [0]*N
    ms = [[{} for i in range(2)] for j in range(M)]
    for cust in range(M):
        fs = [int(x) for x in f.readline().split()]
        for i in range(fs[0]):
            ms[cust][fs[2*i+2]][fs[2*i+1]] = True
    mB = 0
    good = sat(ns, ms, N, M)
    bad = impossible(ns, ms, N, M, mB)
    while not good and not bad:
        mB += 1
        fix (ns, ms, N, M, mB)
        good = sat(ns, ms, N, M)
        bad = impossible(ns, ms, N, M, mB)
    if bad:
        print "Case #%d: IMPOSSIBLE" % (case+1,)
    if good:
        print ("Case #%d: " % (case+1)) + " ".join([str(i) for i in ns])
