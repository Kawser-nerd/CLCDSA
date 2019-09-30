from itertools import product
from collections import Counter

def best(n, grid):
    countrow = set()
    countcol = set()
    countdiag1 = set()
    countdiag2 = set()

    def addchar(i, j, c):
        if c & 2:
            if i in countrow: return False
            if j in countcol: return False
        if c & 1:
            if i + j in countdiag1: return False
            if i - j in countdiag2: return False
        if c & 2:
            countrow.add(i)
            countcol.add(j)
        if c & 1:
            countdiag1.add(i + j)
            countdiag2.add(i - j)
        grid[i][j] |= c
        return True

    for i, j in product(xrange(n), repeat=2):
        res = addchar(i, j, grid[i][j])
        assert res

    avail = Counter(map(sum, product(xrange(n), repeat=2)))
    for i, j in sorted(product(xrange(n), repeat=2), key=lambda (i, j): avail[i + j]):
        addchar(i, j, 1)
        addchar(i, j, 2)

    return grid

mask = {
    '.': 0,
    '+': 1,
    'x': 2,
    'o': 3,
}
imask = {v: k for k, v in mask.items()}

bitcount = [0]*10
for i in xrange(10): bitcount[i] = bitcount[i >> 1] + (i & 1)


for cas in xrange(1,1+input()):
    n, k = map(int, raw_input().strip().split())
    grid = [[0]*n for i in xrange(n)]
    for kk in xrange(k):
        data = raw_input().strip().split()
        c, (i, j) = data[0], map(int, data[1:])
        grid[i-1][j-1] = mask[c]

    ngrid = best(n, map(list, grid))

    changes = []
    value = 0
    for i in xrange(n):
        for j in xrange(n):
            value += bitcount[ngrid[i][j]]
            assert (ngrid[i][j] & grid[i][j]) == grid[i][j]
            if grid[i][j] != ngrid[i][j]:
                changes.append((imask[ngrid[i][j]], i+1, j+1))
    print "Case #%s: %s %s" % (cas, value, len(changes))
    for ch, i, j in changes:
        print ch, i, j

