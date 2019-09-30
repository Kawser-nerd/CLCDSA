# given some sequence, count all possible strictly increasing subsequences.
# doesn't count empty sequence here.

# simple O(n^2) solution:
# C[i] = (number of increasing subsequences ending x[i])
#      = 1 + sum { C[k] for every k < i if x[k] < x[i] }
#
# this is not good for n>=10000; should devise O(n log n) solution.
# 

B = 1000000007
def process_old(seq):
    table = []
    for i in xrange(len(seq)):
        num = 1
        for j in xrange(i):
            if seq[j] < seq[i]: num += table[j]
        table.append(num % B)
    return sum(table) % B

def process(seq):
    # determine order.
    invorder = range(len(seq))
    invorder.sort(key=lambda i:seq[i])
    order = [None] * len(seq)
    for i in xrange(len(seq)): order[invorder[i]] = i

    table = []
    for i in xrange(len(seq)):
        num = 1
        for j in xrange(i):
            if seq[j] < seq[i]: num += table[j]
        table.append(num % B)
    return sum(table) % B

import sys, time
next = iter(sys.stdin).next
ncases = int(next())
for i in xrange(ncases):
    n, m, x, y, z = map(int, next().split())
    seq = [int(next()) for j in xrange(m)]
    realseq = []
    for j in xrange(n):
        realseq.append(seq[j % m])
        seq[j % m] = int((x * seq[j % m] + y * (j + 1)) % z)
    numsubseqs = process(realseq)
    print 'Case #%d: %d' % (i+1, numsubseqs)
    sys.stdout.flush()

