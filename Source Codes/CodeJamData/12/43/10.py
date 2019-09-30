import math
import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        n = int(f.readline())

        peaks = map(int, f.readline().split())

        assert len(peaks) == n-1

        heights = [10000000] + [0] * (n-1)

        works = True
        changed = True
        while changed and works:
            changed = False
            # print heights
            for i in xrange(n-1):
                highest = i + 1
                for j in xrange(i + 2, n):
                    if (heights[j] - heights[i]) * (highest - i) > (heights[highest] - heights[i]) * (j - i):
                        highest = j

                p = peaks[i] - 1
                # print highest, p
                if highest != p:
                    newheight = heights[i] + (p - i) * (heights[highest] - heights[i]) / (highest - i) + 1
                    if newheight > 1e9:
                        works = False
                        break
                    assert newheight > heights[p], (newheight, heights[p])
                    heights[p] = newheight
                    changed = True

                    # print heights

        if works:
            print "Case #%d: %s" % (_t + 1, ' '.join(map(str, heights)))
        else:
            print "Case #%d: Impossible" % (_t + 1)
