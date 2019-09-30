"""
on each day do one of the following:

* request coding set
* request jamming set
* submit coding set
* submit jamming set

problem set may have been either assigned when jammer was in good or bad mood

so possible dynamic programming approach: state is (prefix length, num c/c, num
c/j, num j/c, num j/j)

is it ever advantageous to request the wrong kind of problem set? if you request c and submit it both on j days, then clearly it's better to request j; if you request c on j day and submit it on c day, that's worth 5, but if you request j on j day and submit it on c day, that's also worth 5

so refine state space: always request problem set matching current mood. then state space is (prefix length, num c, num j)

06/11/16 07:14 AM missed that submitted problem must be most recently requested one... blows up complexity of dynamic programming algorithm. needs to be greedy?

06/11/16 07:20 AM wrinkle is that it's legal to request a problem set and never turn it in. e.g. CJC
"""

def solve(seq):
    memo = {}
    def opt(lo, hi):
        if (lo, hi) in memo:
            return memo[lo, hi]
        if lo == hi:
            result = 0
        else:
            best = None
            if hi == len(seq):
                # take paper and never turn it in
                o1 = opt(lo + 1, hi)
                if o1 is not None:
                    best = max(best, o1)
            for i in xrange(lo + 1, hi):
                # take paper on day lo and turn it in on day i
                o1 = opt(lo + 1, i)
                o2 = opt(i + 1, hi)
                if o1 is not None and o2 is not None:
                    best = max(best, o1 + (10 if seq[lo] == seq[i] else 5) + o2)
            result = best
        memo[lo, hi] = result
        return result
    return opt(0, len(seq))

if __name__ == '__main__':
    import sys
    fp = open(sys.argv[1])
    def readline():
        return fp.readline().strip()
    num_cases = int(readline())
    for i in xrange(num_cases):
        seq = readline()
        print "Case #%d: %d" % (i + 1, solve(seq))
