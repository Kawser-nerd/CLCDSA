
T = int(raw_input())
for t in xrange(T):
    E, R, N = map(long,raw_input().split())
    v = map(long, raw_input().split())

    nextBigger = [-1] * N
    for i in range(N):
        for j in range(i+1, N):
            if v[j] > v[i]:
                nextBigger[i] = j
                break
    
    res = 0
    energy = E
    for task in range(N):
        if nextBigger[task] == -1:
            # we are the best option, spend all of it!
            spending = energy
        else:
            difference = nextBigger[task] - task
            spending = max(0, energy + difference * R - E)
            spending = min(spending, energy)

        res = res + spending * v[task]
        energy = min(E, energy - spending + R)

    print "Case #{:d}: {:d}".format(t+1, res)
