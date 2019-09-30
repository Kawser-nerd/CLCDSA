import sys
import numpy as np

in_file = open('b-large.in', 'r')
out_file = open('b.out', 'w')
sys.stdin = in_file
sys.stdout = out_file

def calc(a):
    n = len(a)
    f = np.zeros(shape = (n + 1, n + 1))
    f[0][0] = 1
    for i in xrange(1, n + 1):
        for j in xrange(n + 1):
            f[i][j] += f[i - 1][j] * a[i - 1]
            if j > 0:
                f[i][j] += f[i - 1][j - 1] * (1 - a[i - 1])
    return f[n][n / 2]

T = int(raw_input())
for t in xrange(T):
    n, m = map(int, raw_input().split())
    a = map(float, raw_input().split())
    a.sort()
    ans = 0
    for i in xrange(m + 1):
        b = a[:m - i] + a[n - i:]
        assert len(b) == m
        ans = max(ans, calc(b))
    print 'Case #%d: %.10f' % (t + 1, ans)

in_file.close()
out_file.close()
