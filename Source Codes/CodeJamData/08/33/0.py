# given some sequence, count all possible strictly increasing subsequences.
# doesn't count empty sequence here.

# C[i] = (number of increasing subsequences ending x[i])
#      = 1 + sum { C[k] for every k < i if x[k] < x[i] }

B = 1000000007
def process(seq):
    table = []
    for i in xrange(len(seq)):
        num = 1
        for j in xrange(i):
            if seq[j] < seq[i]: num += table[j]
        table.append(num % B)
    return sum(table) % B

import sys
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

