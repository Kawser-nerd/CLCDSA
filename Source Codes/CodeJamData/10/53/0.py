for casenum in xrange(1,1+int(raw_input())):
    C = int(raw_input())
    vs = [[int(z) for z in raw_input().split()] for j in xrange(C)]
    ve = {}
    for v in vs:
        ve[v[0]] = v[1]
    v = ve
    switches = 0
    v1 = [z for z in ve.keys() if v[z] > 1]
    while (len(v1) > 0):
        for loc in v1:
            if not (v.has_key(loc-1)):
                v[loc-1] = 0
            if not (v.has_key(loc+1)):
                v[loc+1] = 0
            v[loc-1] += v[loc] >> 1
            v[loc+1] += v[loc] >> 1
            switches += v[loc] >> 1
            v[loc] &= 1
        v1 = [z for z in ve.keys() if v[z] > 1]
    print "Case #%d: %d" % (casenum, switches)
