from sys import stdin
from sys import stdout

def find_least(s, p, x):
    m = None
    b = len(s)
    for i in xrange(p, len(s)):
        if s[i] > x and (m is None or s[i] < m):
            m = s[i]
            b = i
    return b

def next_number(N):
    for i in xrange(len(N) - 1, 0, -1):
        if N[i - 1] < N[i]:
            K = N[:i - 1]
            p = find_least(N, i, N[i - 1])
            d = N[p]
            s = list(N[i - 1:p] + N[p + 1:])
            s.sort()
            K += d + ''.join(s)
            break
    else:
        p = find_least(N, 0, '0')
        d = N[p]
        s = list(N[:p] + N[p + 1:])
        s.sort()
        K = d + '0' + ''.join(s)
    return K

T = int(stdin.readline().strip())
for X in xrange(1, T + 1):
    N = stdin.readline().strip()
    K = next_number(N)
    stdout.write('Case #%d: %s\n' % (X, K))
