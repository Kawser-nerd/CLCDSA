import sys
sys.setrecursionlimit(10000)

tt = int(raw_input())
for t in xrange(1, tt+1):
    n = int(raw_input())
    bff = map(lambda x: int(x)-1, raw_input().strip().split())
    ans = 0
    bigcycle = 0
    vsl = [None] * n
    dst = [None] * n
    cyc = [False] * n
    cy2 = [False] * n
    fth = [0] * n
    dth = [0] * n
    vsc = [None] * n

    def dfl(p, r, s):
        vsl[p] = r
        dst[p] = s
        if vsl[bff[p]] is None:
            x = dfl(bff[p], r, s+1)
            if x is not None and s >= x:
                cyc[p] = True
            return x
        elif vsl[bff[p]] == r:
            cyc[p] = True
            cycsize = s-dst[bff[p]]+1
            global bigcycle
            bigcycle = max(bigcycle, cycsize)
            if cycsize == 2:
                cy2[p] = True
                cy2[bff[p]] = True
            return dst[bff[p]]
        else:
            return None

    def dfs(p):
        if vsc[bff[p]] is None:
            dfs(bff[p])
        vsc[p] = vsc[bff[p]]
        if cy2[vsc[p]]:
            dth[p] = dth[bff[p]]+1
            fth[vsc[p]] = max(fth[vsc[p]], dth[p])

    for i in xrange(n):
        if vsl[i] is None:
            dfl(i, i, 0)

    for i in xrange(n):
        if cy2[i]:
            fth[i] = 1
            dth[i] = 1
        if cyc[i]:
            vsc[i] = i

    for i in xrange(n):
        if vsc[i] is None:
            dfs(i)

    ans = max(sum(fth), bigcycle)
    print 'Case #%d: %s' % (t, ans)