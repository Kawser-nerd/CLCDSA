for casenum in xrange(1,1+int(raw_input())):
    [L,N] = [int(z) for z in raw_input().split()]
    Bs = [int(z) for z in raw_input().split()]
    maxB = max(Bs)
    Bs = [z for z in Bs if z != maxB]
    nu = [10 ** 200] * maxB
    nu[0] = 0
    q = [[0,0]]
    while (len(q) > 0):
        qe = q[0]
        q = q[1:]
        if (nu[qe[0]] == qe[1]):
            for b in Bs:
                if (qe[0] + b < maxB):
                    qf = [qe[0] + b, qe[1] + 1]
                else:
                    qf = [qe[0] + b - maxB, qe[1]]
                if qf[1] < nu[qf[0]]:
                    nu[qf[0]] = qf[1]
                    q += [qf]
    if (nu[L % maxB] != (10 ** 200)):
        print "Case #%d: %d" % (casenum, nu[L % maxB] + (L / maxB))
    else:
        print "Case #%d: IMPOSSIBLE" % casenum

