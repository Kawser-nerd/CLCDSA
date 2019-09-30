import sys


def valid(X, R, C):
    if (R * C) % X != 0:
        return False
    if X >= 7:
        return False
    if R < X and C < X:
        return False
    validX = {
            1: lambda r, c: True,
            2: lambda r, c: True,
            3: lambda r, c: r > 1,
            4: lambda r, c: r > 2,
            5: lambda r, c: (r == 3 and c > 5) or r > 3,
            6: lambda r, c: r > 3,
            }
    return validX[X](min(R, C), max(R, C))


def compute(X, R, C):
    if valid(X, R, C):
        return "GABRIEL"
    else:
        return "RICHARD"


def parse():
    X, R, C = map(int, sys.stdin.readline().strip().split())
    return X, R, C


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
