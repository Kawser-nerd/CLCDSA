import re

i = open('1b.in', 'r')

C = int(i.readline())

for c in range(1, C+1):
    N = int(i.readline())
    M = int(i.readline())

    p = []
    r = [0] * N

    for m in range(M):
        ci = i.readline().split()
        ci.pop(0)
        d = {}
        while ci:
            k = int(ci.pop(0))
            v = int(ci.pop(0))
            d[k] = v
        p.append(d)

    ok = 1
    cont = 1

    while cont:
        cont = 0
        for n in range(1,N+1):
            # check if anyone is only satisifible with malted
            for m in range(M):
                if (len(p[m]) == 1) and (n in p[m]) and (p[m][n] == 1):
                    if (r[n-1]==0): cont = 1

                    r[n-1] = 1

                    # remove all satisifible with non-melted
                    for w in range(M):
                        if (n in p[w]) and (p[w][n] == 0):
                            del p[w][n]
                        if len(p[w]) == 0:
                            ok = 0
                            break

                    if not ok: break
            if not ok: break


    if ok:
        print "Case #%d: %s" % (c, ' '.join([str(z) for z in r]))
    else:
        print "Case #%d: IMPOSSIBLE" % c
