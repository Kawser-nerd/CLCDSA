"""
Jerry Ma
C.py
"""

import sys, itertools

def solve(it):
    n = int(sys.stdin.readline())
    words = []
    for _ in xrange(n):
        line = sys.stdin.readline()
        words.append(tuple(line.strip().split()))
    ans = 0
    for mask in itertools.product([True, False], repeat=n):
        newans = n - sum(mask)
        if newans <= ans:
            continue
        first_words = set(w[0] for i, w in enumerate(words) if mask[i])
        second_words = set(w[1] for i, w in enumerate(words) if mask[i])
        good = True
        for i, w in enumerate(words):
            if w[0] not in first_words or w[1] not in second_words:
                good = False
                break
        if good:
            ans = newans
    print >> sys.stderr, it
    print 'Case #%d: %d' % (it, ans)

iters = int(sys.stdin.readline())

for it in xrange(iters):
    solve(it + 1)
