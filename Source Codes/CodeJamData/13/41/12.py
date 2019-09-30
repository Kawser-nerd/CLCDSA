from sys import *
from heapq import *

def write(msg):
    stdout.write(msg)
    fo.write(msg)

def writeln(msg):
    write(str(msg) + '\n')

def readint():
    return int(fi.readline())

def readints():
    return [int(X) for X in fi.readline().split()]

def readstr():
    return fi.readline().rstrip()

fni = "%s-%s-%s.in" % (argv[1], argv[2], argv[3])
fno = "%s-%s-%s.out" % (argv[1], argv[2], argv[3])
fi = open(fni, 'r')
fo = open(fno, 'w')

def cost(N, k):
    return N*(N+1)/2 - (N-k)*(N-k+1)/2

num_cases = readint()
for case in range(1, 1+num_cases):
    (N, M) = readints()
    entry = dict()
    exit = dict()
    stops = set()
    legit = 0
    for m in range(M):
        (o, e, p) = readints()
        if not entry.has_key(o):
             entry[o] = p
        else:
             entry[o] += p
        if not exit.has_key(e):
            exit[e] = p
        else:
            exit[e] += p
        stops.add(e)
        stops.add(o)
        legit += p * cost(N, e-o)
    tickets = dict()
    dodgy = 0
    for s in sorted(list(stops)):
        if entry.has_key(s):
            if tickets.has_key(s):
                tickets[s] += entry[s]
            else:
                tickets[s] = entry[s]
        if exit.has_key(s):
            n = exit[s]
            while n > 0:
                f = max(tickets.items())
                if f[1] > n:
                    dodgy = (dodgy + n * cost(N, s-f[0])) % 1000002013
                    tickets[f[0]] -= n
                    n = 0
                else:
                    dodgy = (dodgy + f[1] * cost(N, s-f[0])) % 1000002013
                    n -= f[1]
                    del tickets[f[0]]
    writeln("Case #%d: %d" % (case, (1000002013 + legit - dodgy) % 1000002013))

