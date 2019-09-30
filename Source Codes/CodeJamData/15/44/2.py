import sys


buf = {}

def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def gcdlcm(a, b):
    g = gcd(a, b)
    return g, a * b / g


def dp(C, remaining, last_type, repeat):
    if remaining == 0:
        return 1
    key = (remaining, last_type, repeat)
    if key in buf:
        return buf[key]
    total = 0
    if last_type != 3 and remaining >= 2:
        total += dp(C, remaining - 2, 3, repeat)
    if last_type != 12:
        total += dp(C, remaining - 1, 12, repeat)
        if remaining >= 2 and C % 3 == 0:
            n, new_repeat = gcdlcm(repeat, 3)
            total += n * dp(C, remaining - 2, 12, new_repeat)
        if remaining >= 2 and C % 6 == 0:
            n, new_repeat = gcdlcm(repeat, 6)
            total += n * dp(C, remaining - 2, 12, new_repeat)
        if remaining >= 3 and C % 4 == 0:
            n, new_repeat = gcdlcm(repeat, 4)
            total += n * dp(C, remaining - 3, 12, new_repeat)
    buf[key] = total % 1000000007
    return buf[key]


def compute(R, C):
    global buf
    buf = {}
    return dp(C, R, 0, 1)


def parse():
    R, C = map(int, sys.stdin.readline().strip().split())
    return R, C


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
