from hopcroftkarp import HopcroftKarp # source: https://pypi.python.org/pypi/hopcroftkarp/1.2.3, GPL
from itertools import combinations
from collections import defaultdict
import sys

_in = open(sys.argv[1])
def raw(): return _in.readline().rstrip('\n')
def ints(): return map(int, raw().split())
raw_input = raw # we all forget sometimes

def solve_small(L):
    n = len(L)
    for j in range(n-2, 0, -1):
        for orig in combinations(range(n), n-j):
            left = set()
            right = set()
            for i in orig:
                left.add(L[i][0])
                right.add(L[i][1])
            good = True
            for i in range(n):
                if i not in orig:
                    if L[i][0] not in left or L[i][1] not in right:
                        good = False
                        break
            if good:
                return j
    return 0

def solve(L):
    n = len(L)
    graph = defaultdict(set)
    left = set()
    right = set()
    for u, v in L:
        left.add(u)
        right.add(v)
        graph['l'+u].add('r'+v)
    sol = HopcroftKarp(graph).maximum_matching()
    orig = len(left) + len(right) - len(sol)/2
    return n - orig

if __name__ == '__main__':
    num_cases, = ints()
    for case_num in xrange(1, num_cases + 1):
        N, = ints()
        L = []
        for i in range(N):
            L.append(tuple(raw().split()))
        print "Case #{}: {}".format(case_num, solve(L))
