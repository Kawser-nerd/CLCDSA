# This is a Sage file
import random
from collections import defaultdict

n_cases = int(raw_input())
for ctr in xrange(n_cases):
    print('Case #{0}:'.format(ctr+1))
    r, n, m, k = (int(x) for x in raw_input().split(' '))
    for snum in xrange(r):
        prods = [int(x) for x in raw_input().split(' ')]
        facts = [factor(x) for x in prods]
        musts = defaultdict(int)
        maybes = []
        for prod, fact in zip(prods, facts):
            if prod == 1:
                continue
            fact.sort()
            for (prime, power) in reversed(fact):
                if prime == 2:
                    if power == 1:
                        musts[2] = max(1, musts[2])
                    else:
                        if sum(musts.itervalues()) < n-1:
                            maybes.append(2)
                            maybes.append(4)
                        else:
                            musts[4] = max(1, musts[4])
                else:
                    musts[prime] = max(musts[prime], power)
        picks = []
        for k, v in musts.iteritems():
            picks += [k]*v
        picks += [2]*(n - sum(musts.itervalues()))
        print(''.join((str(x) for x in picks)))
