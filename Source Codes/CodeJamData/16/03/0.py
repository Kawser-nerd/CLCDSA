from random import *

def fromBase(s, b):
    n = 0
    for c in s:
        n = b * n + ord(c) - ord('0')
    return n

print 'Case #1:'
n, q = map(int, raw_input().split())
M = 1000
a = set()
while len(a) < q:
    s = '1' + ''.join(['01'[randrange(2)] for i in xrange(n - 2)]) + '1'
    if s in a:
        continue
    l = []
    for b in xrange(2, 11):
        N = fromBase(s, b)
        t = -1
        for j in xrange(2, M + 1):
            if j >= N:
                break
            if N % j == 0:
                t = j
                break
        l.append(t)
    if -1 in l:
        continue
    print s, ' '.join(map(str, l))
    a.add(s)
