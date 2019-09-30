class BIT:
    def __init__(self, n):
        self.S = [0] * (n + 1)
        self.N = n

    def tot(self, k):
        i = k
        a = 0
        while i > 0:
            a += self.S[i]
            i -= (i & -i)
        return a

    def inc(self, k, v):
        i = k
        while i <= self.N:
            self.S[i] += v
            i += (i & -i)

def reader(inFile):
    dummy = inFile.getInts()
    return inFile.getInts()

from fractions import gcd

def solver(nums):
    sn = sorted(nums)
    n = len(nums)
    nl = {sn[i]:i for i in xrange(n)}
    nums = [nl[i] for i in nums]
    nl = {nums[i]:i+1 for i in xrange(n)}
    bit = BIT(n)
    print n
    for i in xrange(n):
        bit.inc(i+1,1)
    lower = 1
    upper = n
    tot = 0
    for i in xrange(n):
        v = nl[i]
        cur = bit.tot(v)
        if (cur - lower) > (upper - cur):
            tot += upper - cur
            bit.inc(v+1,-1)
            upper -= 1
        else:
            tot += cur - lower
            bit.inc(1,1)
            bit.inc(v,-1)
            lower += 1
    return tot

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/luke/gcj/2014/2/b/", "b").run()

