from collections import defaultdict
for case in xrange(input()):
    n, A, B, C, D, x0, y0, M = map(int, raw_input().split())
    x = x0
    y = y0

    d = {}
    for i in xrange(3):
        for j in xrange(3):
            d[(i,j)] = 0

    d[(x%3,y%3)] += 1
    #print x, y

    for i in xrange(1,n):
        x = (A*x+B) % M
        y = (C*y+D) % M
        d[(x%3,y%3)] += 1
        #print x, y
    cnt = 0
    for i in d.keys():
        for j in d.keys():
            k = (3-((i[0]+j[0])%3))%3, (3-((i[1]+j[1])%3))%3
            v = sorted([i,j,k])
            if v != [i,j,k]: continue
            dv = [d[k] for k in v]
            if dv[0] == 0: continue
            vv = 0
            if v[0] == v[1] and v[1] == v[2]:
                vv = dv[0] * (dv[1]-1) * (dv[2]-2) / 6
            elif v[0] == v[1]:
                vv = dv[0] * (dv[1]-1) * dv[2] / 2
            elif v[2] == v[1]:
                vv = dv[0] * dv[1] * (dv[2]-1) / 2
            else:
                vv = dv[0] * dv[1] * dv[2]
            cnt += vv

        
    print 'Case #%d: %d' % (case+1, cnt)
