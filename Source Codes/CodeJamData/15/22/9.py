def go(r, c, n, s, p):
    a = [[(i > 0) + (i < r - 1) + (j > 0) + (j < c - 1) for j in xrange(c)] for i in xrange(r)]
    for b in xrange(4, -1, -1):
        for i in xrange(r):
            for j in xrange(c):
                if n <= 0:
                    return s / 2
                if a[i][j] == b and (i + j) % 2 == p:
                    s -= b * 2
                    a[i][j] -= b
                    if i > 0 and a[i-1][j]:
                        a[i-1][j] -= 1
                    if i < r - 1 and a[i+1][j]:
                        a[i+1][j] -= 1
                    if j > 0 and a[i][j-1]:
                        a[i][j-1] -= 1
                    if j < c - 1 and a[i][j+1]:
                        a[i][j+1] -= 1
                    n -= 1
    for b in xrange(4, -1, -1):
        for i in xrange(r):
            for j in xrange(c):
                if n <= 0:
                    return s / 2
                if a[i][j] == b and (i + j) % 2 == 1 - p:
                    s -= b * 2
                    a[i][j] -= b
                    if i > 0 and a[i-1][j]:
                        a[i-1][j] -= 1
                    if i < r - 1 and a[i+1][j]:
                        a[i+1][j] -= 1
                    if j > 0 and a[i][j-1]:
                        a[i][j-1] -= 1
                    if j < c - 1 and a[i][j+1]:
                        a[i][j+1] -= 1
                    n -= 1
    return s / 2
def solve():
    r, c, n = map(int, raw_input().split())
    s = r * c * 4 - r * 2 - c * 2
    n = r * c - n
    return min(go(r, c, n, s, 0), go(r, c, n, s, 1))

T = int(raw_input())
for t in xrange(T):
    print "Case #%d: %d" % (t + 1, solve())
