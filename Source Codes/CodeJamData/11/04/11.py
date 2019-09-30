#!/usr/bin/python
import sys
from sys import stderr

def Solve(numbers):
    print >>stderr, numbers
    hits = 0
    already = set()
    for i,n in enumerate(numbers):
        i += 1
        if n in already:
            continue
        if n == i:
            already.add(n)
        else:
            cluster = set()
            cluster.add(n)
            while True:
                n = numbers[n-1]
                if n in cluster:
                    break
                cluster.add(n)
                already.add(n)
            print >>stderr, "C ", cluster
            hits += len(cluster)

    return hits

f = open(sys.argv[1])

T = int(f.readline())
for t in range(T):
    f.readline()
    numbers = map(int, f.readline().split())
    print "Case #%d: %f" % (t+1, Solve(numbers))
    
