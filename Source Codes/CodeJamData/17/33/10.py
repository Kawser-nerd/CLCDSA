def ints():
    return [int(x) for x in raw_input().strip().split()]
def floats():
    return [float(x) for x in raw_input().strip().split()]

T, = ints()
for t in range(T):
    N,K = ints()
    U, = floats()
    p = floats()
    assert len(p) == N

    p.sort()

    counted = []  #(prob,mult) pairs
    for prob in p:
        if counted:
            if counted[-1][0] == prob:
                counted[-1][1] += 1
                continue
        counted.append([prob,1])

    #print counted, U

    i = 0
    while True:
        prob,mult = counted[i]
        if i < len(counted) - 1:
            gap = counted[i+1][0] - prob  # next prob - prob
        else:
            gap = 1 - prob
        if gap * mult >= U - 0.000001:
            counted[i][0] += U / mult
            break
        U -= gap * mult
        counted[i][0] += U / mult
        # promote to next
        counted.pop(0)
        counted[0][1] += mult

    #print counted

    totalprob = 1.
    for prob,mult in counted:
        totalprob *= prob ** mult

    print "Case #%d: %s" % (t+1, totalprob)

    
    
