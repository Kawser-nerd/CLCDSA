def reader(inFile):
    (numStops, numPairs) = tuple(inFile.getInts())
    return (numStops,[tuple(inFile.getInts()) for k in xrange(numPairs)])

def f(N,k):
    return k * N - ((k * (k - 1)) / 2)

from sys import stderr

def solver((numStops, routes)):
    cost = sum([r[2] * f(numStops, r[1] - r[0]) for r in routes])
    minCost = 0
    events = [(r[i], i, r[2]) for r in routes for i in xrange(2)]
    events.sort()
    queue = []
    for event in events:
        if event[1] == 0:
            queue += [(event[0], event[2])]
        else:
            numToHandle = event[2]
            while (numToHandle > 0):
                num = min(queue[-1][1], numToHandle)
                minCost += num * f(numStops, event[0] - queue[-1][0])
                numToHandle -= num
                if num == queue[-1][1]:
                    queue = queue[:-1]
                else:
                    queue[-1] = (queue[-1][0], queue[-1][1] - num)
    return (cost - minCost) % 1000002013

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/lpebody/gcj/2013_2/a/", "a").run()
