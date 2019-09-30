import sys


def compute(S):
    if S == '':
        return ''
    x = max(S)
    p = S.find(x)
    y = compute(S[:p])
    z = filter(lambda c: c != x, S[p:])
    return (x * (len(S) - p - len(z))) + y + z


def parse():
    S = sys.stdin.readline().strip()
    return S,


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    count = 1
    part = 0
    if len(sys.argv) == 3:
        part = int(sys.argv[1])
        count = int(sys.argv[2])
    for i in xrange(T):
        data = parse()
        if i * count >= part * T and i * count < (part + 1) * T:
            result = compute(*data)
            print "Case #%d: %s" % (i + 1, result)
