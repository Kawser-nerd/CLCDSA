import sys
from collections import defaultdict


M = [
        "sijk",
        "iSkJ",
        "jKSi",
        "kjIS",
        ]

MUL = defaultdict(dict)


def change_case(x):
    if x.islower():
        return x.upper()
    else:
        return x.lower()


def init_map():
    global MUL
    for i, a in enumerate(M[0]):
        for j, b in enumerate(M[0]):
            MUL[a][b] = M[i][j]
            MUL[a.upper()][b] = change_case(M[i][j])
            MUL[a][b.upper()] = change_case(M[i][j])
            MUL[a.upper()][b.upper()] = M[i][j]


def mul(a, b):
    return MUL[a][b]


def min_left(s, c):
    r = 's'
    for i in xrange(len(s)):
        r = mul(r, s[i])
        if r == c:
            return i + 1
    return None


def min_right(s, c):
    r = 's'
    for i in xrange(len(s)):
        r = mul(s[len(s) - i - 1], r)
        if r == c:
            return i + 1
    return None


def compute(L, X, ijk):
    ijk_value = reduce(mul, ijk)
    total = reduce(mul, [ijk_value] * (X % 4), 's')
    if total != 'S':
        return "NO"
    ijk4 = ijk * 4
    left = min_left(ijk4, 'i')
    right = min_right(ijk4, 'k')
    if left is None or right is None:
        return "NO"
    if left + right > L * X:
        return "NO"
    return "YES"


def parse():
    L, X = map(int, sys.stdin.readline().strip().split())
    ijk = sys.stdin.readline().strip()
    return L, X, ijk


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    init_map()
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
