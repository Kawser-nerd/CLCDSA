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
        N, X = map(int, f.readline().split())
        disks = map(int, f.readline().split())
        assert len(disks) == N

        disks.sort()
        disks = collections.deque(disks)

        r = 0
        while disks:
            x1 = disks.pop()
            if disks and x1 + disks[0] <= X:
                disks.popleft()
            r += 1
        print "Case #%d: %d" % (_T+1, r)
