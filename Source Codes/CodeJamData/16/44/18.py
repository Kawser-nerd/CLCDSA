import sys
from itertools import combinations, permutations
from collections import defaultdict

_in = open(sys.argv[1])
def raw(): return _in.readline().rstrip('\n')
def ints(): return map(int, raw().split())
raw_input = raw # we all forget sometimes

def valid(N, new, arr, free):
    #if flag:
    #    print "valid", W, N, new, arr
    if not arr:
        return True
    p = arr[0]
    poss = new[p] & free
    if not poss:
        return False
    return all(valid(N, new, arr[1:], free - set([choice])) for choice in poss)
    ##free = range(N)
    ##maybe_taken = set()
    ##for t, p in enumerate(arr):
    ##    #print W[p], new[p]
    ##    poss = set(i for i in range(N) if W[p][i]).union(new[p])
    ##    if flag: print "POSS", poss
    ##    max_taken = min(t, len(poss & maybe_taken))
    ##    if max_taken >= len(poss):
    ##        if flag:
    ##            print "fail"
    ##            print t,p,arr
    ##        return False
    ##    maybe_taken |= poss
    ###print "pass"
    ##return True

def solve(N, W):
    squares = [(i,j) for i in range(N) for j in range(N) if not W[i][j]]
    #print squares
    for fix in range(len(squares)+1):
        for comb in combinations(squares, fix):
            #flag = (comb == ((0,2), (2,0), (2,1)))
            new = defaultdict(set)
            for x,y in comb:
                new[x].add(y)
            for x in range(N):
                for y in range(N):
                    if W[x][y]:
                        new[x].add(y)
            #print new
            if all(valid(N, new, arr, set(range(N))) for arr in permutations(range(N), N)):
                return fix
    raise ValueError

if __name__ == '__main__':
    num_cases, = ints()
    for case_num in xrange(1, num_cases + 1):
        N, = ints()
        W = []
        for i in range(N):
            W.append(map(int, raw().strip()))
        print "Case #{}: {}".format(case_num, solve(N, W))
