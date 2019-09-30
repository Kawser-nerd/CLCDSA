import collections
import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N = int(f.readline())
        nums = map(int, f.readline().split())

        r = 0
        while nums:
            m = min(nums)
            i = nums.index(m)

            r += min(i, len(nums)-1-i)
            del nums[i]

        print "Case #%d: %d" % (_T+1, r)
