#!/usr/bin/env python

import sys

def readline():
    return map(int, raw_input().strip().split())

def solve():
    n, p, q, r, s = readline()
    t = [(i * p + q) % r + s for i in xrange(n)]
    st = [0]
    for ti in t:
        st.append(st[-1] + ti)
    res = [0]
    def test(a, b, c):
        r = a + b + c - max(a, b, c)
        if r > res[0]:
            res[0] = r
    j = 0
    while st[j + 1] < st[n] - st[j + 1]:
        j += 1
    for i in xrange(n):
        test(st[i], st[j] - st[i], st[n] - st[j])
        while st[j + 1] - st[i] < st[n] - st[j + 1]:
            j += 1
            test(st[i], st[j] - st[i], st[n] - st[j])
        test(st[i], st[j + 1] - st[i], st[n] - st[j + 1])
    return '{:.10f}'.format(float(res[0]) / st[n])


def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        print >> sys.stderr, 'Case #{}'.format(i)
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
