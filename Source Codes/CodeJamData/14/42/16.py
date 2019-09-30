#!/usr/bin/env python

def solve(N, A):
    counts = [0] * N
    for i in xrange(N):
        for j in xrange(i):
            counts[i] += A[j] > A[i]
    indices = [a[1] for a in sorted((A[i], i) for i in xrange(N))]
    return sum(min(counts[indices[i]], N - i - 1 - counts[indices[i]])
               for i in xrange(N))

T = int(raw_input())
for x in xrange(1, T + 1):
    N = int(raw_input())
    A = map(int, raw_input().split())
    print 'Case #%d: %s' % (x, solve(N, A))
