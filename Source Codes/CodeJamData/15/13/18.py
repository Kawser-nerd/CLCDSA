#!/usr/bin/env python2.7

T = int(raw_input())
for x in xrange(1, T + 1):
    N = int(raw_input())
    trees = [map(int, raw_input().split()) + [j] for j in xrange(N)]
    trees.sort()
    def boundary(mask):
        res = [False] * N
        if len(mask) <= 3:
            for t in mask:
                res[t] = True
            return res
        a = mask[0]
        while True:
            b = mask[0]
            for j in mask[1:]:
                if b == a:
                    b = j
                else:
                    xab = trees[b][0] - trees[a][0]
                    yab = trees[b][1] - trees[a][1]
                    xaj = trees[j][0] - trees[a][0]
                    yaj = trees[j][1] - trees[a][1]
                    v = xab * yaj - xaj * yab
                    if v > 0 or v == 0 and xaj**2 + yaj**2 > xab**2 + yab**2:
                        b = j
            for j in mask:
                xab = trees[b][0] - trees[a][0]
                yab = trees[b][1] - trees[a][1]
                xaj = trees[j][0] - trees[a][0]
                yaj = trees[j][1] - trees[a][1]
                if xab * yaj - xaj * yab == 0:
                    res[j] = True
            a = b
            if a == mask[0]:
                break
        return res
    y = [N] * N
    for j in xrange(1 << N):
        c = N - bin(j).count('1')
        b = boundary(filter(lambda k: (1 << k) & j, xrange(N)))
        for k in xrange(N):
            if b[k]:
                y[trees[k][2]] = min(y[trees[k][2]], c)
    print 'Case #{}:'.format(x)
    print '\n'.join(map(str, y))
