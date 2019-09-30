import sys

def compute(A, B, p):
    q = 1.0
    smin = B + 2.0
    for i in xrange(len(p)):
        q *= p[i]
        s = (A - i - 1) + q * (B - i) + (1.0 - q) * (B - i + B + 1)
        if s < smin:
            smin = s
    return "%f" % smin



def parse():
    A, B = map(int, sys.stdin.readline().strip().split(' '))
    p = map(float, sys.stdin.readline().strip().split(' '))
    return (A, B, p)


if __name__ == "__main__":
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
