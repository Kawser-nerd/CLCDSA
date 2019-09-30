import sys


DIRS = {
        '>': (0, 1),
        '<': (0, -1),
        '^': (-1, 0),
        'v': (1, 0),
        }


def escapes(R, C, m, i, j, d):
    for n in xrange(1, 1000):
        r = i + DIRS[d][0] * n
        c = j + DIRS[d][1] * n
        if r < 0 or r >= R or c < 0 or c >= C:
            return True
        if m[r][c] != '.':
            return False
    return False


def compute(R, C, m):
    total = 0
    for i in xrange(R):
        for j in xrange(C):
            if m[i][j] == '.':
                continue
            if not escapes(R, C, m, i, j, m[i][j]):
                continue
            found = False
            for c in DIRS.keys():
                if not escapes(R, C, m, i, j, c):
                    found = True
                    break
            if not found:
                return "IMPOSSIBLE"
            total += 1
    return total


def parse():
    R, C = map(int, sys.stdin.readline().strip().split())
    m = []
    for i in xrange(R):
        m.append(sys.stdin.readline().strip())
    return R, C, m


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
