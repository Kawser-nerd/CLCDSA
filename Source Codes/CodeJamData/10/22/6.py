#!/usr/bin/env python


c = raw_input()

for cs in xrange(1, int(c)+1):
    n, k, b, t = [int(z) for z in raw_input().strip().split()]
    x = [int(z) for z in raw_input().strip().split()]
    v = [int(z) for z in raw_input().strip().split()]

    hopeful = []
    hopeless = []

    for i in xrange(0, n):
        pos = x[i]
        speed = v[i]
        if pos + speed * t >= b:
            #   hopeful
            hopeful.append( (pos, speed) )
        else:
            #   hopeless
            hopeless.append( (pos, speed) )

    if len(hopeful) < k:
        print "Case #%d: IMPOSSIBLE" % cs
        continue

    jumpovers = []

    for p1, sp1 in hopeful:
        jumpover = 0
        e1 = p1 + sp1 * t
        for p2, sp2 in hopeless:
            e2 = p2 + sp2 * t

            assert e2 < b

            if p1 < p2 and e2 < e1:
                jumpover += 1

        jumpovers.append(jumpover)

    jumpovers.sort()
    print "Case #%d: %d" % (cs, sum(jumpovers[:k]))
        

            
