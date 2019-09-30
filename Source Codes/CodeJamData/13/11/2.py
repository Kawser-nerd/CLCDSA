import sys

def num_paint(r, k):
    return 2 * k * r + 2 * k * k - k

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        r, t = map(int, f.readline().split())

        low = 1
        high = 10**18

        while high > low:
            guess = (low + high + 1) / 2
            if num_paint(r, guess) > t:
                high = guess - 1
            else:
                low = guess
        print "Case #%d: %d" % (_T+1, low)
