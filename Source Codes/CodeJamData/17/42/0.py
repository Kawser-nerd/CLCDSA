from sys import stdin

def getInts():
    return tuple(int(z) for z in stdin.readline().split())

(T,)=getInts()

for tc in xrange(1,1+T):
    (N,C,M) = getInts()
    pbs = [getInts() for k in xrange(M)]
    tickets = [[] for i in xrange(1, C+1)]
    reqs = [0 for i in xrange(N)]
    for pb in pbs:
        tickets[pb[1]-1].append(pb[0])
        reqs[pb[0]-1] += 1
    tickets = [z for z in tickets if any(z)]
    trips = max(len(z) for z in tickets)
    totsofar = 0
    for i in xrange(N):
        totsofar += reqs[i]
        trips = max(trips, (totsofar + i) / (i + 1))
    upgrades = 0
    for i in xrange(N):
        upgrades += max(0, reqs[i] - trips)
    print "Case #{}: {} {}".format(tc, trips, upgrades)
