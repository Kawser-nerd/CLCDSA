def ints():
    return [int(x) for x in raw_input().strip().split()]

T, = ints()
for t in range(T):
    N1,N2 = ints()
    if N1+N2 == 0:
        print "Case #%d: 2" % (t+1,)
        continue

    ints1 = []
    for i in range(N1):
        c,d = ints()
        l = d - c
        ints1.append((c,d,l,1))
    ints2 = []
    for i in range(N2):
        c,d = ints()
        l = d - c
        ints2.append((c,d,l,2))

    time1 = sum(x[2] for x in ints1)
    time2 = sum(x[2] for x in ints2)

    allints = sorted(ints1 + ints2)
    gaps = [None,[],[]]  # between n's activities
    swaps = 0  # forces swaps
    slack = 0
    for i in range(0,N1+N2):
        intv = allints[i]
        if i == 0:
            previntv = allints[-1]
            prevend = previntv[1] - 24*60
        else:
            previntv = allints[i-1]
            prevend = previntv[1]
        dist = intv[0] - prevend
        #print intv, "dist", dist
        if intv[3] == previntv[3]:
            # same person
            gaps[intv[3]].append(dist)
        else:
            slack += dist
            swaps += 1

    gaps[1].sort()
    gaps[2].sort()
    gaptime1 = sum(gaps[1])
    gaptime2 = sum(gaps[2])
    #print "times", time1, time2, "slack", slack

    half = 12*60
    did = False

    assert time1 + gaptime1 + slack + time2 + gaptime2 == 24*60

    while time1 + gaptime1 + slack < half:
        # take a gap
        dist = gaps[2].pop()
        time1 += dist
        swaps += 2
        did = True


    while time2 + gaptime2 + slack < half:
        # take a gap
        dist = gaps[1].pop()
        time2 += dist
        swaps += 2
        assert did==False


    print "Case #%d: %s" % (t+1, swaps)

    
    
