# P = number of pieces in each pack
# goal: order groups to maximize number of groups that don't receive any leftover chocolate; output is that number
# probably admits greedy approach...
# we can ignore groups that are multiples of P because we can just get them out of the way first (they wouldn't change state otherwise)
# group gets leftover chocolate iff partial sum of groups before it = 0 mod P
# so we can also take all groups mod P
# limits are really small on P... 2 <= P <= 4
# so we want to divide groups into chunks such that each chunk's sum is 0 mod P; then each each chunk's first group will get no leftover chocolate
# and one more group at the end that receives fresh bar

# ok, small dataset:
# P = 2: pair odd groups
# P = 3: group can be made of 1 2, 1 1 1, 2 2 2
# P = 4: group can be made of 1 1 1 1, 1 1 2, 1 3, 2 2, 3 3 3 3, 3 3 2

# general approach: number of groups is small so we can be greedy??

# for P = 4 we could pose this as graph search where we're trying to find min path from start to finish in terms of number of groups that receive leftover chocolate... but that's a fairly large state space? but we can reduce it to counts of groups mod P

import collections
import heapq

def dec(t, i):
    return tuple((x - 1) if i == j else x for (j, x) in enumerate(t))

def solve(p, groups):
    c = collections.Counter(g % p for g in groups)
    # state = (size of current chocolate pack, remaining counts)
    init_state = (0, tuple(sum(g % p == i for g in groups) for i in xrange(p)))
    def neighbors(st):
        pack, counts = st
        for i in xrange(p):
            if counts[i] > 0:
                st2 = ((pack + i) % p, dec(counts, i))
                yield (st2, 1 if pack != 0 else 0)
    def done(st):
        pack, counts = st
        return all(x == 0 for x in st[1])
    q = [(0, init_state)]
    seen = set()
    while q:
        dist, st = heapq.heappop(q)
        if st in seen:
            continue
        if done(st):
            return len(groups) - dist
        seen.add(st)
        for (st2, ddist) in neighbors(st):
            heapq.heappush(q, (dist + ddist, st2))
    assert False, "no path to end"

if __name__ == '__main__':
    import sys
    fp = open(sys.argv[1])
    def readline():
        return fp.readline().strip()
    num_cases = int(readline())
    for i in xrange(num_cases):
        ng, p = [int(x) for x in readline().split()]
        groups = [int(x) for x in readline().split()]
        print "Case #%d: %d" % (i + 1, solve(p, groups))
