#!/usr/local/bin/pypy
# run with PyPy 2.6.1

from pprint import pprint

def read_strings():
    return raw_input().strip().split(' ')

def read_ints():
    return [int(x) for x in read_strings()]

INF = 10**15

test_count, = read_ints()
for test in xrange(1, test_count + 1):
    n, q = read_ints()
    e = [None] * n
    s = [None] * n
    for i in xrange(n):
        e[i], s[i] = read_ints()
    d = [None] * n
    for i in xrange(n):
        d[i] = read_ints()
        for j in xrange(len(d[i])):
            if d[i][j] == -1:
                d[i][j] = INF

    for k in xrange(n):
        for i in xrange(n):
            for j in xrange(n):
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])

    # pprint(d)

    d2 = [[INF] * n for _ in xrange(n)]

    for i in xrange(n):
        for j in xrange(n):
            if d[i][j] <= e[i]:
                d2[i][j] = d[i][j] / float(s[i])

    # pprint(d2)

    for k in xrange(n):
        for i in xrange(n):
            for j in xrange(n):
                d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j])

    ans = []
    for i in xrange(q):
        u, v = read_ints()
        ans.append(d2[u-1][v-1])

    ans = ['{:.10f}'.format(x) for x in ans]
    print 'Case #{}: {}'.format(test, ' '.join(ans))
