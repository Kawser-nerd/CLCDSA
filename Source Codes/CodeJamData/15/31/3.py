import sys

def solve(r, c, w):
    return r * (c // w) + (w - 1 if c % w == 0 else w)

def testcase(i):
    r, c, w = map(int, sys.stdin.readline().split())
    print 'Case #%d: %d' % (i, solve(r, c, w))


if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for i in range(t):
        testcase(i + 1)

