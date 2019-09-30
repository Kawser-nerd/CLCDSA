from itertools import product
from collections import Counter, defaultdict

N = 3
M = 5
K = 7

problist = None

def make_problist():
    global problist
    problist = defaultdict(Counter)

    for t in product(range(2, M+1), repeat=N):
        t = tuple(sorted(t))

        for k in product((0,1), repeat=N):
            p = 1
            for kk, tt in zip(k, t):
                if kk:
                    p *= tt
            problist[p][t] += 1

make_problist()
#print problist

def main():
    import sys
    sys.stdin.readline()
    sys.stdin.readline()
    print "Case #1:"

    for _ in range(100):
        ps = map(int, sys.stdin.readline().split())
        P = problist[1].viewkeys()
        for p in ps:
            P &= problist[p].viewkeys()
        P = {p: 1 for p in P}
        for p in ps:
            for pp in P:
                P[pp] *= problist[p][pp]
        result = max(P.items(), key=lambda x: x[1])[0]
        print ''.join(str(x) for x in result)
main()
