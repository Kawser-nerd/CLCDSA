#!/usr/bin/python
import sys
import itertools
from itertools import * 


def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))


def mySol(params):
    N = params[0]
    nums = params[1:]
    if len(nums)!=N: raise Exception('bad parsing')
    
    sums={}

    
    for subset in powerset(nums):
        s = sum(subset)
        for other in sums.setdefault(s,set()):
            if subset==other: raise Exception('something is wrong')
            subset = set(subset)
            other = set(other)
            t = subset.intersection(other)
            subset.symmetric_difference_update(t)
            other.symmetric_difference_update(t)
            res = '\n'+ ' '.join([str(x) for x in subset]) + '\n' + \
                ' '.join([str(x) for x in other])
            return res
        sums[s].add(subset)
    return 'Impossible'



T = int(sys.stdin.readline())
for i in xrange(T):
    params = [int(x) for x in sys.stdin.readline().split()]
    res = mySol(params)
    print 'Case #%d: %s' % (i+1,res)



