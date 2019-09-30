#!/usr/local/bin/pypy
# run with PyPy 2.6.1

def read_strings():
    return raw_input().strip().split(' ')

def read_ints():
    return [int(x) for x in read_strings()]

def can(d, k, s, v):
    t = d / float(v)
    for i in xrange(len(k)):
        if k[i] + t * s[i] < t * v:
            return False
    return True

test_count, = read_ints()
for test in xrange(1, test_count + 1):
    d, n = read_ints()
    k = [None] * n
    s = [None] * n
    for i in xrange(n):
        k[i], s[i] = read_ints()
    l = 0
    r = 1e15
    for it in xrange(100):
        m = (l + r) / 2.0
        if can(d, k, s, m):
            l = m
        else:
            r = m

    print 'Case #{}: {:.10f}'.format(test, m)
